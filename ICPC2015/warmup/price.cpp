#include <iostream>
#include <cstdio>
#include <vector>
#include <memory>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
int main(){
	int N, W;
	scanf("%d %d", &N, &W);
	vector<vector<ii>> price(W + 1);
	for (int i = 0; i <= W; i++){
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; j++){
			int p;
			scanf("%d", &p);
			price[i].push_back({p, 0});
		}
		for (int j = 0; j < K; j++){
			scanf("%d", &price[i][j].second);
		}
	}

	vector<ii> old_dp(N + 1, {-1, 0});
	old_dp[0].first = 0;

	int max = 0, index = 0;
	for (int i = 0; i <= W; i++){
		vector<ii> dp(N + 1, {-1, 0});
		for (int j = 0; j < price[i].size(); j++){
			for (int l = 0; l <= N; l++)
				if (old_dp[l].first != -1){
					int money = 0, seat = 0;
					if (price[i][j].second + l <= N){
						money = price[i][j].second * price[i][j].first;
						seat = l + price[i][j].second;
					}
					else{
						money = (N - l) * price[i][j].first;
						seat = N;
					}

					if (old_dp[l].first + money >  dp[seat].first){
						dp[seat].first = old_dp[l].first + money;
						dp[seat].second = old_dp[l].second;
						if (i == 0)
							dp[seat].second = j;
					}
					else if (old_dp[l].first + money == dp[seat].first){
						if (price[0][old_dp[l].second].first < price[0][dp[seat].second].first)
							dp[seat].second = old_dp[l].second;
					}
				}
		}
		old_dp = move(dp);
		
	}
	
	for (int i = 0; i <= N; i++)
		if (old_dp[i].first > max){
			max = old_dp[i].first;
			index = old_dp[i].second;
		}
		else if (old_dp[i].first == max){
			if (price[0][old_dp[i].second].first < price[0][index].first)
				index = old_dp[i].second;
		}
			
	printf("%d\n%d\n", max, price[0][index].first);	
}
	
