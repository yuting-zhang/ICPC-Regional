#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

void DFS(int row, int col, char (*board)[15], int (*cluster)[15], int counter) {
    const int walk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    cluster[row][col] = counter;

    for (int i = 0; i < 4; i++) {
        int r = row + walk[i][0];
        int c = col + walk[i][1];
        if (r >= 0 && r < 10 && c >= 0 && c < 15) {
            if (cluster[r][c] == 0 && board[r][c] == board[row][col])
                DFS(r, c, board, cluster, counter);
        }
    }
}

void cleanBoard(char (*board)[15]) {
    bool empty[15];
    for (int i = 0; i < 15; i++)
        empty[i] = true;

    for (int c = 0; c < 15; c++) {
        int space = -1;
        for (int r = 9 ; r >= 0; r--) {
            if (board[r][c] != ' ')
                empty[c] = false;

            if (board[r][c] != ' ' && space != -1) {
                board[space][c] = board[r][c];
                board[r][c] = ' ';
                space--;
            }
            else if (board[r][c] == ' ' && space == -1)
                space = r;
        }
    }

    int space = -1;
    for (int c = 0; c < 15; c++) {
        if (empty[c] && space == -1)
            space = c;
        else if (!empty[c] && space != -1) {
            for (int r = 0; r < 10; r++) {
                board[r][space] = board[r][c];
                board[r][c] = ' ';
            }
            space++;
        }
    }
}

int main() {
    int N;
    scanf("%d ", &N);
    for (int tc = 1; tc <= N; tc++) {
        if (tc != 1)
            printf("\n");
        printf("Game %d:\n\n", tc);

        char board[10][15];
        for (int r = 0; r < 10; r++)
            for (int c = 0; c < 15; c++)
                scanf(" %c ", &board[r][c]);

        int score = 0; 
        int remain = 150;
        int step = 0;

        while (true) {
            int cluster[10][15]; 
            memset(cluster, 0, sizeof(cluster));
            int counter = 0;
            for (int r = 0; r < 10; r++)
                for (int c = 0; c < 15; c++)
                    if (cluster[r][c] == 0 && board[r][c] != ' ')
                        DFS(r, c, board, cluster, ++counter);

            if (counter == 0) {
                score += 1000;
                break;
            }

            int clusterNum[counter];
            memset(clusterNum, 0, sizeof (clusterNum));

            pair<int, int> leftBot[counter];
            for (int i = 0; i < counter; i++)
                leftBot[i] = make_pair(-1, -1);
            
            for (int r = 0; r < 10; r++)
                for (int c = 0; c < 15; c++) {
                    int index = cluster[r][c] - 1;
                    clusterNum[index]++;
                    if (leftBot[index].first == -1 ||
                        c < leftBot[index].second ||
                        c == leftBot[index].second && r > leftBot[index].first) {
                        leftBot[index] = make_pair(r, c);
                    }
                }

            int maxCluster = 0;
            for (int i = 0; i < counter; i++) {
                if (clusterNum[i] > clusterNum[maxCluster] || 
                    clusterNum[i] ==  clusterNum[maxCluster] &&
                   (leftBot[i].second < leftBot[maxCluster].second ||
                    leftBot[i].second == leftBot[maxCluster].second &&
                    leftBot[i].first > leftBot[maxCluster].first)) 
                    maxCluster = i;
            }

            if (clusterNum[maxCluster] < 2) 
                break;

            int newScore = (clusterNum[maxCluster] - 2) * (clusterNum[maxCluster] - 2);
            remain -= clusterNum[maxCluster];
            score += newScore;

            step++;
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
                step, 10 - leftBot[maxCluster].first, 
                leftBot[maxCluster].second + 1,
                clusterNum[maxCluster], 
                board[leftBot[maxCluster].first][leftBot[maxCluster].second],
                newScore);

            for (int r = 0; r < 10; r++)
                for (int c = 0; c < 15; c++)
                    if (cluster[r][c] == maxCluster + 1)
                        board[r][c] = ' ';
                    
                
            cleanBoard(board);
        }
        printf("Final score: %d, with %d balls remaining.\n", score, remain);
    }
}

