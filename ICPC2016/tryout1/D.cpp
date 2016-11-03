#include <bits/stdc++.h>

using namespace std;

const unsigned long long BIG = ((unsigned long long)1 << 31) - 1;
const unsigned long long INF = ((unsigned long long)1 << 40);

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n, true));
    
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        for (int j = 0; j < n; j++)
            if (line[j] == '#')
                grid[i][j] = false;
    }

    unsigned long long dp[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            if (i || j) 
                if (grid[i][j]) {
                    if (i > 0)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % BIG;
                    if (j > 0)
                        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % BIG;
                }

    if (dp[n - 1][n - 1] != 0) {
        cout << dp[n - 1][n - 1] << "\n";
        return 0;
    }

    bool visited[n][n];
    memset(visited, 0, sizeof visited);
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});

    bool found = false;
    while (!q.empty() && !found) {
       auto front = q.front();
       q.pop();
       int r = front.first, c = front.second;
       int walk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
       for (int i = 0; i < 4; i++) {
            int n_r = r + walk[i][0];
            int n_c = c + walk[i][1];
            if (n_r >= 0 && n_r < n && n_c >= 0 && n_c < n && !visited[n_r][n_c] && grid[n_r][n_c]) {
                if (n_r == n - 1 && n_c == n - 1) {
                    found = true;
                    break;
                }
                q.push({n_r, n_c});
                visited[n_r][n_c] = true;
            }
       }
    }
    if (found)
        cout << "THE GAME IS A LIE\n";
    else
        cout << "INCONCEIVABLE\n";
}
