#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
long long dorm[1000];
long long cost[1000][1000];

int main()
{
	cin>>N>>M>>K;
	for (int i=0; i<N; i++)
	{
		int n;
		cin>>n;
		dorm[n]++;
	}
	vector<long long> poss;
	for (int i=1; i<=M; i++)
	{
		long long s = dorm[i];
		cost[i][0] = s*(s+1)/2;
		for (int j=1; j<=K; j++)
		{
			long long sp = s / (j + 1);
			long long hc = s - (j + 1) * sp;
			long long lc = j + 1 - hc;
			cost[i][j] = hc * (sp + 1)* (sp + 2) / 2 + lc * sp * (sp + 1) / 2;
			poss.push_back(cost[i][j-1] - cost[i][j]);
		}
	}
	sort(poss.begin(), poss.end());
	reverse(poss.begin(), poss.end());
	long long sum = 0;
	for (int i=1; i<=M; i++)
	{
		sum += dorm[i] * (dorm[i] + 1) / 2;
	}
	for (int i=0; i<K; i++)
		sum -= poss[i];
	cout<<sum<<endl;
	return 0;
}
