#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 50;

long long com[maxn][maxn];
vector<int> data;

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

long long f(int sum, int n){
	return com[sum+n-1][n-1];
}

long long equ(vector<int> v, int sum){
	long long a = 0;
	int size = v.size();
	if(size == 1)
		return 1;
	int fi = v[size-1];
	for(int i=0;i<v[size-1];i++)
		a += f(sum-i, size-1);
	v.pop_back();
	return a + equ(v, sum-fi);
		
}

long long ans(vector<int> v, int sum){
	long long a = 0;
	int size = v.size();
	for(int i=0;i<sum;i++){
	//	printf("i:%d size:%d\n", i, size);
		a += f(i, size);
	//	printf("aa: %lld\n", a);
	}
//	printf("a: %lld\n", a);
	a += equ(v, sum);
	return a;
}


int main()
{
//	freopen("data.txt","r",stdin);
	pre();
	int n;
	while(scanf("%d", &n) && n){
		data.clear();
		int sum = 0;
		for(int i=0;i<n;i++){
			int h;
			scanf("%d", &h);
			data.push_back(h);
			sum += h;
		}
	//	for(int i=1;i<30;i++)
	//		for(int j=0;j<i;j++)
	//			printf("%d %d %lld\n",i,j, com[i][j]);
		reverse(data.begin(), data.end());
		printf("%lld\n", ans(data, sum));
	}
	return 0;
}
