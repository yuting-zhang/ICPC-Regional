#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main(){
	vector<bool> states(100000, false);
	int n, m;
	scanf("%d %d", &n, &m);
	queue<pair<int, int>> q;
	q.push({n, 0});
	int answer = 0;
	states[n] = true;
	while (!q.empty()){
		auto u = q.front();
		q.pop();
		int num = u.first, count = u.second;
		if (num < 0)
			continue;
		if (num == m){
			answer = count;
			break;
		}
			
		if (num * 2 < 100000 && !states[num * 2]){
			states[num * 2] = true;
			q.push({num * 2, count + 1});
		}
		if (num - 1 >= 0 && !states[num - 1]){
			states[num - 1] = true;
			q.push({num - 1, count + 1});
		}
			
	}
	printf("%d\n", answer);
}
