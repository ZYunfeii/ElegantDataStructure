#include <bits/stdc++.h>
using namespace std;
typedef struct Entry {
    int id;
    int weight; // 有向图权重
} Entry;

class State {
public:
    // 图节点的 id
    int id;
    // 从 start 节点到当前节点的距离
    int distFromStart;
    State(int id, int distFromStart) {
        this->id = id;
        this->distFromStart = distFromStart;
    }
    bool operator<(const State& right) const {
        return distFromStart > right.distFromStart; // 左大右小，小顶堆
    }
};
// disTo为start到每个节点的最短距离， graph采用邻接表表示，具体里面存储的内容自定义，比如我这是Entry来记录weight
void dijkstra(vector<vector<Entry>> graph, int start, vector<int>& disTo) {
    disTo = vector<int>(disTo.size(), INT_MAX);
    disTo[start] = 0;
    priority_queue<State> pq;
    pq.push(State(start, 0));
    while (!pq.empty()) {
        State s = pq.top();
        pq.pop();
        int curId = s.id;
        int curDist = s.distFromStart;
        if (curDist > disTo[curId]) continue; // 这一句可有可无，当发现当前走法比记录的距离还长时，没有必要搜子节点了
        for (int i = 0; i < graph[curId].size(); ++i) {
            Entry e = graph[curId][i];
            int nextDist = curDist + e.weight;
            if (nextDist < disTo[e.id]) {
                disTo[e.id] = nextDist;
                pq.push(State(e.id, nextDist)); // 只有在发现距离更短的前提下才入队
            }
        }
    }
}

int main() {
    int sz = 6;
    // https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-03a72/dijkstra-s-6d0b2/ 图
    vector<vector<Entry>> graph(sz, vector<Entry>());
    graph[0].push_back(Entry{4, 5});
    graph[0].push_back(Entry{3, 8});
    graph[0].push_back(Entry{1, 9});

    graph[1].push_back(Entry{2, 2});
    
    graph[2].push_back(Entry{5, 1});

    graph[3].push_back(Entry{5, 2});

    graph[4].push_back(Entry{5, 6});

    vector<int> disTo(sz, 0);
    dijkstra(graph, 0, disTo);
    // 0 9 11 8 5 10
    for (int i = 0; i < disTo.size(); ++i) {
        cout << disTo[i] << " ";
    } cout << endl; 
    return 0;
}