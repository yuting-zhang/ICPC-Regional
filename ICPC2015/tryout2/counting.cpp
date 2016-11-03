#include <iostream>
#include <utility>
#include <cstdio>
#include <vector>
#include <map>
#include <memory>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	map<pair<int, int>, long long> count;
	count[make_pair(0, 0)] = 1;

	vector<pair<int, int>> vecs(N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &vecs[i].first, &vecs[i].second);
	
	for (int i = 0; i < N; i++){
		auto new_map = count;
		for(const auto& it: count) 
			new_map[make_pair(it.first.first + vecs[i].first, it.first.second + vecs[i].second)] +=
			count[it.first];
		count = move(new_map);
	}
	cout << count[make_pair(0, 0)] - 1<< "\n";
	return 0;
}
