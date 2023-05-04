#include <bits/stdc++.h>
using namespace std;

void floyd(vector<vector<int>>& graph) {
    for (int k = 0; k < graph.size(); ++k) {
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph.size(); ++j) {
                if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    int sz = 6;
    // https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-03a72/dijkstra-s-6d0b2/ 图
    // 用邻接矩阵
    vector<vector<int>> graph = {
        {0, 9, INT_MAX, 8, 5, INT_MAX},
        {INT_MAX, 0, 2, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, 0, INT_MAX, INT_MAX, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 2},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 6},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}
    };

    floyd(graph);
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph.size(); ++j) {
            cout << graph[i][j] << " ";
        } cout << endl;
    }
    return 0;
}