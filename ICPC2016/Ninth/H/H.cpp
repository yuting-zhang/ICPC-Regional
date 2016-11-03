#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
		int n, k;
		while (cin >> k >> n){
				k++;
				double tight = 0;
				vector<vector<double>> dp(n, vector<double>(k, 0));

				for (int i = 0; i < k; i++)
						dp[0][i] = 1;
				for (int i = 1; i < n; i++)
						for (int j = 0; j < k; j++){
								dp[i][j] = dp[i - 1][j];
								if (j > 0)
										dp[i][j] += dp[i - 1][j - 1];
								if (j < k - 1)
										dp[i][j] += dp[i - 1][j + 1];
						}
				for (int i = 0; i < k; i++)
						tight += dp[n - 1][i];

				double answer = tight;
				for (int i = 0; i < n ;i++)
						answer /= k;
				printf("%.5f\n", answer * 100);
		}
}
