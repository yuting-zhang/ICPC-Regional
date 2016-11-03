#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int N;
	scanf("%d\n", &N);
	while (N--){
		string line;
		getline(cin, line);
		int K = ceil(sqrt(line.size()));
		vector<vector<char>> table(K, vector<char>(K));
		int count = 0;
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				if (count < line.size()){
					table[i][j] = line[count];
					count++;
				}
				else
					table[i][j] = '*';
		auto result = table;
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				result[j][K - 1 - i] = table[i][j];
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				if (result[i][j] != '*')
					cout << result[i][j];
		cout << "\n";
	}
}
