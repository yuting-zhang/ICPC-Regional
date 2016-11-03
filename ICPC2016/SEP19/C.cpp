#include <bits/stdc++.h>

using namespace std;

bool grid[1005][1005];
bool sea[1005][1005];
int N, M;

void mark(int r, int c) {
    sea[r][c] = true;
    int walk[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        int row = r + walk[i][0];
        int col = c + walk[i][1];
        if (row >= 0 && col >= 0 && row < N && col < M
                && !grid[row][col] && !sea[row][col])
            mark(row, col);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            char ch;
            scanf(" %c", &ch);
            if (ch == '0')
                grid[i][j] = false;
            else
                grid[i][j] = true;
        }

    memset(sea, 0, sizeof sea);

    for (int i = 0; i < N; i++) {
        if (!grid[i][0] && !sea[i][0]) 
            mark(i, 0);
        if (!grid[i][M - 1] && !sea[i][M - 1])
            mark(i, M - 1);
    }

    for (int i = 0; i < M; i++) {
        if (!grid[0][i] && !sea[0][i]) 
            mark(0, i);
        if (!grid[N - 1][i] && !sea[N - 1][i])
            mark(N - 1, i);
    }

    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << sea[i][j];
        cout << "\n";
    }*/
    int coast = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (!grid[i][j])
                continue;
            int walk[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
            for (int k = 0; k < 4; k++) {
                int row = i + walk[k][0];
                int col = j + walk[k][1];
                if (row < 0 || col < 0 || row >= N || col >= M) {
                    //cout << row << " " << col << "\n";
                    coast++;
                }
                else if (sea[row][col]) {
                    //cout << row << " " << col << "\n";
                    coast++;
                }
            }
        }
    cout << coast << "\n";
}
