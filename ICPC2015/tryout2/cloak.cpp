#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> paces(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &paces[i]);
	sort(paces.begin(), paces.end());
	int answer = 0;
	if (paces.size() % 2 == 0){
		for (int i = 2; i < paces.size(); i += 2)
			answer += max(paces[i], paces[i + 1]);
		answer += (paces.size() - 2) / 2 * (max(paces[0], paces[1]) + paces[0] + paces[1]);
		answer += max(paces[0], paces[1]);
	}
	else{
		for (int i = 3; i < paces.size(); i += 2)
			answer += max(paces[i], paces[i + 1]);
		answer += (paces.size() - 3) / 2 * (max(paces[0], paces[1]) + paces[0] + paces[1]);
		answer += max(paces[2], paces[0]);
		answer += paces[0];
		answer += max(paces[0], paces[1]);
	}
	cout << answer << "\n";
}
