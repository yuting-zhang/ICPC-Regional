#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 50;

long long com[maxn][maxn];

long long pre(){
	for(int i=0;i<maxn;i++){
		com[i][0] = 1;
		com[i][i] = 1;
	}
	for(int i=1;i<maxn;i++){
		for(int j=1;j<i;j++){
			com[i][j] = com[i-1][j] + com[i-1][j-1];
		}
	}
}

int main()
{
	int T;
	pre();
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%lld\n", com[n][n-m+1]);
	}
}
