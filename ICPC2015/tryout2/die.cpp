#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<int>> getC(){
	vector<vector<int>> C(15, vector<int>(15, 0));
	C[0][0] = 1;
	for (int i = 1; i < 15; i++){
		C[0][i] = 1;
		for (int j = 1; j <= i; j++)
			C[j][i] = C[j][i - 1] + C[j - 1][i - 1];
	}
	return C;
}

int factorial(int n){
	int ret = 1;
	for (int i = 1; i <= n; i++)
		ret *= i;
	return ret;
}
int main(){
	vector<vector<int>> C = getC();
	int N;
	scanf("%d\n", &N);
	while (N--){
		int R, S, X, Y, W;
		scanf("%d %d %d %d %d", &R, &S, &X, &Y, &W);
		double chance = 0;
		for (int i = X; i <= Y; i++){
			chance += pow(((double)S - R + 1) / S, i) * C[i][Y] *  pow((double)(R - 1) / S, Y - i); 
		}
		if (chance * W  > 1)
			printf("yes\n");
		else
			printf("no\n");
	}
}
