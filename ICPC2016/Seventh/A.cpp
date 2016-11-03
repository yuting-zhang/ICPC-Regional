#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

bool DFS(int u, int p){
	if (visited[u])
		return true;
	visited[u] = true;
	bool cycle = false;
	for (int v : adjList[u])
		if (v != p)
			if (DFS(v, u))
				return true;
	return false;
				
}
int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	adjList.assign(N, vector<int>());
	visited.assign(N, false);
	for (int i = 0; i < M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	bool cycle = DFS(0, -1);
	bool connected = true;
	for (int i = 0; i < N; i++)
		if (!visited[i])
			connected = false;
	if (!cycle && connected)
		printf("YES\n");
	else
		printf("NO\n");
}
