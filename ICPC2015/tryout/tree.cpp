#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> trees(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &trees[i]);
	sort(trees.rbegin(), trees.rend());
	int day = 0;
	for (int i = 0; i < N; i++)
		if (trees[i] + i + 1 > day)
			day = trees[i] + i + 1;
	printf("%d", day + 1);
	return 0;
}
