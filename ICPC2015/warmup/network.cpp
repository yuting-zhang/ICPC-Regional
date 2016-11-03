#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;

vector<bool> taken;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<bool> insecure;
vector<vector<ii>> adjList;

void process(int vtx){
	taken[vtx] = true;
	for (int j = 0; j < (int)adjList[vtx].size(); j++){
		ii v = adjList[vtx][j];
		if (!taken[v.first] && !insecure[v.first]);
			pq.push(ii(v.second, v.first));
	}
}
int main(){
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	adjList.assign(n, vector<ii>());
	insecure.assign(n, false);

	for (int i = 0; i < p; i++){
		int bandit;
		scanf("%d", &bandit);
		bandit--;
		insecure[bandit] = true;
	}

	
	for (int i = 0; i < m; i++){
		int x, y, l;
		scanf("%d %d %d", &x, &y, &l);
		x--; y--;
		adjList[x].push_back({y, l});
		adjList[y].push_back({x, l});
	}

	taken.assign(n, false);
	int safe = -1;
	for (int i = 0; i < n; i++)
		if (!insecure[i]){
			safe = i;
			break;
		}
		
	bool possible = true;	
	int mst_cost = 0;
	if (safe != -1){
		process(safe);
		while (!pq.empty()){
			ii front = pq.top();
			pq.pop();
			int u = front.second, w = front.first;
			if (insecure[u])
				continue;
			if (!taken[u]){
				mst_cost += w;
				process(u);
			}
		}
		for (int i = 0; i < n; i++)
			if (!insecure[i] && !taken[i]){
				possible = false;
				break;
			}
		if (possible){
			for (int i = 0; i < n; i++)
				if (insecure[i]){
					bool ok = false;
					int cost = INT_MAX;
					for (int j = 0; j < adjList[i].size(); j++)
						if (!insecure[adjList[i][j].first]){
							ok = true;
							cost = min(cost, adjList[i][j].second);
						}
					if (!ok){
						possible = false;
						break;
					}
					mst_cost += cost;
				}
					
		}
	}
	else{
		if (m != (n - 1) * n / 2)
			possible = false;
		
		if (possible){
			for (int i = 0; i < n; i++)
				for (int j = 0; j < adjList[i].size(); j++)
					mst_cost += adjList[i][j].second;
			mst_cost /= 2;
		}
	}
	if (possible)
		printf("%d\n", mst_cost);
	else
		printf("impossible\n");
}
