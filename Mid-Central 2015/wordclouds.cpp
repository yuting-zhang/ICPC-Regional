#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
	int N, C;
	while (cin >> N >> C){
		vector<int> height(N), width(N);
		for (int i = 0; i < N; i++)
			cin >> width[i] >> height[i];
		vector<int> dp(N + 1, INT_MAX);
		dp[N] = 0;
		for (int i = N - 1; i >= 0; i--){
			int curr_height = 0, curr_width = 0;

			for (int j = i; j < N; j++){
				if (curr_width + width[j] <= C){
					curr_height = max(curr_height, height[j]);
					curr_width = curr_width + width[j];
					dp[i] = min(dp[i], curr_height + dp[j + 1]);
				}
				else
					break;
			}

		}
		cout << dp[0] << '\n';
	}
}
