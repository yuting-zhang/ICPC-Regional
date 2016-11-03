#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int getVal(char ch){
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	if (ch >= 'A' && ch <= 'Z')
		return (ch - 'A') + 10;
	return (ch - 'a') + 36;
}

int main(){
	string line;
	while (getline(cin, line) && line != "end"){
		long long sum = 0;
		for (int i = 0; i < line.size(); i++){
			sum += getVal(line[i]);
		}
		if (sum % 61 == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
