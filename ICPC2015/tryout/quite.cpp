#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string line;
	while (getline(cin, line)){
		for (int i = 0; i < line.size(); i++)
			if (line[i] >= 'A' && line[i] <= 'Z')
				line[i] = line[i] + ('a' - 'A');
		if (line.find("problem") != string::npos)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
