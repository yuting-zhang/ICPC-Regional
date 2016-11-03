#include <iostream>
#include <vector>

using namespace std;

vector<int> dfs_low, dfs_num;
int dfsNumberCounter;
vector<vector<int>> adjList;
vector<int> dfs_parent;
int dfsRoot, rootChildren;
int row, col, N;
vector<int> S;
vector<int> visited;
int numSCC;

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for (int v : adjList[u]){
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		numSCC++;
	}
}

int getIndex(int r, int c){
	return r * col + c;
}

int main(){
	scanf("%d %d", &row, &col);
	N = row * col;
	adjList.assign(N, vector<int>());
	dfs_low.assign(N, 0);
	dfs_num.assign(N, -1);
	dfsNumberCounter = 0;
	numSCC = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++){
			char ch;
			scanf("	%c ", &ch);
			if (ch == 'S')
				adjList[getIndex(i, j)].push_back(getIndex(i + 1, j));
			if (ch == 'W')
				adjList[getIndex(i, j)].push_back(getIndex(i, j - 1));
			if (ch == 'E')
				adjList[getIndex(i, j)].push_back(getIndex(i, j + 1));
			if (ch == 'N')
				adjList[getIndex(i, j)].push_back(getIndex(i - 1, j));
		}
	for (int i = 0; i < N; i++)
		if (dfs_num[i] == -1){
			visited.assign(N, false);
			S.clear();
			tarjanSCC(i);
		}
	printf("%d\n", numSCC);
}
