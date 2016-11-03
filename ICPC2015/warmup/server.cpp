#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int n, T;
	scanf("%d %d", &n, &T);
	vector<int> times(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &times[i]);

	int answer = 0;
	while (answer < n && T - times[answer] >= 0){
		T -= times[answer];
		answer++;
	}
	printf("%d\n", answer);
}
