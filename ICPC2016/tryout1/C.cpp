#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int digit[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char ch;
            cin >> ch;
            digit[i][j] = ch - '0';
        }

    pair<int, int> adjList[n][m][4];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int walk[4][2] = {{0, digit[i][j]}, {0, -digit[i][j]}, {digit[i][j], 0}, {-digit[i][j], 0}};
            for (int k = 0; k < 4; k++) {
                int row = i + walk[k][0], col = j + walk[k][1];
                if (row >= 0 && row < n && col >= 0 && col < m)
                    adjList[i][j][k] = {row, col};
                else
                    adjList[i][j][k] = {-1, -1};
            }
        }


    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0,0}});

    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int d = front.first, r = front.second.first, c = front.second.second;
        if (d > dist[r][c])
            continue;
        for (int i = 0; i < 4; i++) {
            if (adjList[r][c][i].first != -1) {
                auto new_p = adjList[r][c][i];
                if (dist[r][c] + 1 < dist[new_p.first][new_p.second]) {
                    dist[new_p.first][new_p.second] = dist[r][c] + 1;
                    pq.push({dist[new_p.first][new_p.second], {new_p.first, new_p.second}});
                }
            }
        }
    }

    if (dist[n - 1][m - 1] == INT_MAX)
        cout << -1 << "\n";
    else
        cout << dist[n - 1][m - 1] << "\n";
}
