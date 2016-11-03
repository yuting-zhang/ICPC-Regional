#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	int N;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++){
		string line;
		getline(cin, line);
		if (line.size() >= 10 && line.substr(0, 10) == "Simon says")
			cout << line.substr(10) << "\n";
	}
	return 0;
}
