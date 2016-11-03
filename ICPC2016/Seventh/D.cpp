#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> gift(N);
	for (int i = 0; i < N; i++){
		int u;
		scanf("%d", &u);
		gift[u - 1] = i + 1;
	}
	for (int i = 0; i < N - 1; i++)
		printf("%d ", gift[i]);
	printf("%d\n", gift[N - 1]);
		
}
