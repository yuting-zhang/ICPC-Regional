#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(){
	string name;
	getline(cin, name);
	vector<bool> count(26, false);
	for (int i = 0; i < name.size(); i++)
		count[name[i] - 'a'] = true;
	int distinct = 0;
	for (int i = 0; i < 26; i++)
		if (count[i])
			distinct++;
	if (distinct % 2 == 0)
		printf("CHAT WITH HER!\n");
	else
		printf("IGNORE HIM!\n");
}
