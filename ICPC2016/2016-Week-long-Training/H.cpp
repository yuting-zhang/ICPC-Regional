#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> sticks;
map<int, int> hash;
int selected;

bool solve(int goal, int curr) {
	if (selected == sticks.size() && curr == 0)
		return true;
	else if (selected == sticks.size())
		return false;

	for (map<int, int>::reverse_iterator it = hash.rbegin(); it != hash.rend(); it++) {
		if (it->second > 0) {
			if (it->first + curr == goal) {
				selected++;
				it->second--;
				curr = 0;
				if (solve(goal, curr))
					return true;
				curr = goal - it->first;
				selected--;
				it->second++;
			}
			else {
				if (it->first + curr > goal)
					return false;
				selected++;
				it->second--;
				curr += it->first;
				if (solve(goal, curr))
					return true;
				curr -= it->first;
				selected--;
				it->second++;
			}
		}
	}
	return false;
}

int main() {
	int N;
	while (scanf("%d", &N) == 1 && N) {
		sticks.assign(N, 0);
		hash.clear();

		int total = 0;
		int small = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &sticks[i]);
			total += sticks[i];
			hash[sticks[i]]++;
			small = max(small, sticks[i]);
		}
		
		selected = 0;

		for (int i = small; i <= total; i++) {
			if (total % i == 0 && solve(i, 0)) {
				printf("%d\n", i);
				break;
			}
		}
	}
}
