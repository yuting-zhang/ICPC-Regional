#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
	int row, col, startCol;
	while (scanf("%d %d %d", &row, &col, &startCol) == 3 && row && col && startCol) {
		int grid[row][col];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				char ch;
				scanf(" %c ", &ch);
				if (ch == 'N')
					grid[i][j] = 0;
				else if (ch == 'E')
					grid[i][j] = 1;
				else if (ch == 'S')
					grid[i][j] = 2;
				else 
					grid[i][j] = 3;
			}

		int walk[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

		int currRow = 0, currCol = startCol - 1;
		int visited[row][col];
		memset(visited, 0, sizeof visited);
		
		visited[currRow][currCol] = 1;

		bool cycle = false;
		int exit = 0;
		int preCycle = 0;
		int inCycle = 0;

		while (true) {
			int newRow = currRow + walk[grid[currRow][currCol]][0];
			int newCol = currCol + walk[grid[currRow][currCol]][1];

			if (newRow < 0 || newRow >= row || newCol < 0 || newCol >= col) {
				exit = visited[currRow][currCol];
				break;
			}

			if (visited[newRow][newCol]) {
				cycle = true;
				preCycle = visited[newRow][newCol] - 1;
				inCycle = visited[currRow][currCol] - visited[newRow][newCol] + 1;
				break;
			}

			visited[newRow][newCol] = visited[currRow][currCol] + 1;
			currRow = newRow;
			currCol = newCol;
		}

		if (!cycle)
			printf("%d step(s) to exit\n", exit);
		else
			printf("%d step(s) before a loop of %d step(s)\n", preCycle, inCycle);
	}
	return 0;
}
