#include <bits/stdc++.h>
using namespace std;

enum {
    UP = 0,
    LEFT,
    RIGHT,
    DOWN
};

vector<vector<int>> visited;

void printvis(vector<vector<int>>& visited) {
    for (int i = 0; i < visited.size(); ++i) {
        for (int j = 0; j < visited[0].size(); ++j) {
            cout << visited[i][j] << " ";
        } cout << endl;
    }
    cout << endl;
}

bool dfs(vector<vector<int>>& m, vector<int>& start, vector<int>& dest, int i, int j, int direc) {
    if (i < 0 || i >= m.size() || j < 0 || j >= m[0].size()) {
        return false;
    }
    if (i == dest[0] && j == dest[1]) {
        return true;
    }
    if (direc == LEFT) {
        if (j == 0) return false;
        if (m[i][j - 1] == 1) return false;
    }
    if (direc == RIGHT) {
        if (j == m[0].size() - 1) return false;
        if (m[i][j + 1] == 1) return false;
    }
    if (direc == UP) {
        if (i == 0) return false;
        if (m[i - 1][j] == 1) return false;
    }
    if (direc == DOWN) {
        if (i == m.size() - 1) return false;
        if (m[i + 1][j] == 1) return false;
    }
    
    switch (direc) {
        case UP:
            while (i - 1 >= 0 && m[i - 1][j] != 1) {
                cout << i << " " << j << endl;
                i--;
                if (visited[i][j]) return false;
                visited[i][j] = true;
                printvis(visited);
            }
            if (dfs(m, start, dest, i, j, LEFT)) return true;
            if (dfs(m, start, dest, i, j, RIGHT)) return true;
            break;
        case LEFT:
            while (j - 1 >= 0 && m[i][j - 1] != 1) {
                cout << i << " " << j << endl;
                j--;
                if (visited[i][j]) return false;
                visited[i][j] = true;
                printvis(visited);
            }
            if (dfs(m, start, dest, i, j, UP)) return true;
            if (dfs(m, start, dest, i, j, DOWN)) return true;
            break;        
        case RIGHT:
            while (j + 1 < m[0].size() && m[i][j + 1] != 1) {
                cout << i << " " << j << endl;
                j++;
                if (visited[i][j]) return false;
                visited[i][j] = true;
                printvis(visited);
            }
            if (dfs(m, start, dest, i, j, UP)) return true;
            if (dfs(m, start, dest, i, j, DOWN)) return true;
            break;
        case DOWN:
            while (i + 1 < m.size() && m[i + 1][j] != 1) {
                cout << i << " " << j << endl;
                i++;
                if (visited[i][j]) return false;
                visited[i][j] = true;
                printvis(visited);
            }
            if (dfs(m, start, dest, i, j, LEFT)) return true;
            if (dfs(m, start, dest, i, j, RIGHT)) return true;
            break;
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
    vector<int> dest = {4, 0};
    visited = vector<vector<int>>(m.size(), vector<int>(m[0].size(), 0));
    cout << dfs(m, start, dest, start[0], start[1], LEFT) || dfs(m, start, dest, start[0], start[1], RIGHT) 
    || dfs(m, start, dest, start[0], start[1], UP) || dfs(m, start, dest, start[0], start[1], DOWN);
    return 0;
}