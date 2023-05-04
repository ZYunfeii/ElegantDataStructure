#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> direc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> visited;

bool bfs(vector<vector<int>>& m, vector<int>& start, vector<int>& dest) {
    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    visited[start[0]][start[1]] = true;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto p = q.front();
            q.pop();
            
            if (p.first == dest[0] && p.second == dest[1]) return true;
            for (auto& d : direc) {
                int x = p.first + d[0];
                int y = p.second + d[1];
                while (x >= 0 && y >= 0 && x < m.size() && y < m[0].size() && m[x][y] != 1) {
                    x += d[0];
                    y += d[1];
                }
                x -= d[0];
                y -= d[1];
                cout << x << " " <<  y << endl;

                if (!visited[x][y]) {
                    q.push({x, y});
                    visited[x][y] = true;
                }
                    
            }
        }
    }
    return false;
}

int main() {
    
    vector<vector<int>> m = {{0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 0}};
    vector<int> start = {0, 4};
    vector<int> dest = {4, 4};
    visited = vector<vector<int>>(m.size(), vector<int>(m[0].size(), 0));
    cout << bfs(m, start, dest);
    return 0;
}