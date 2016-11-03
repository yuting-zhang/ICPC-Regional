#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main(){
	int f,s,g,u,d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	vector<bool> floors(f + 1, false);
	queue<pair<int, int>> states;
	pair<int, int> initial_state;

	initial_state.first = s;
	initial_state.second = 0;
	states.push(initial_state);
	floors[s] = true;

	while (!states.empty()){
		pair<int, int> state = states.front();
		states.pop();
		if (state.first == g){
			printf("%d\n", state.second);
			return 0;
		}
		if (state.first + u <= f && floors[state.first + u] == false){
			states.push({state.first + u, state.second + 1});
			floors[state.first + u] = true;
		}
		if (state.first - d > 0 && floors[state.first - d] == false){
			states.push({state.first - d, state.second + 1});
			floors[state.first - d] = true;
		}
	}
	printf("use the stairs\n");
	return 0;
}
