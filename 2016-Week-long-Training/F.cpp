#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string line;
	cin >> line;

	vector<vector<string> > solution(line.size() + 1, vector<string>(line.size() + 1));

	for (int i = 0; i < line.size(); i++)
		if (line[i] == '(' || line[i] == ')')
			solution[i][1] = "()";
		else
			solution[i][1] = "[]";
	
	for (int i = 2; i <= line.size(); i++)
		for (int j = 0; j <= line.size() - i; j++) {
			int k = j + i - 1;

			if (line[j] == '(' && line[k] == ')' ||
				line[j] == '[' && line[k] == ']')
				solution[j][i] = line[j] + solution[j + 1][i - 2] + line[k];

			for (int l = 1; l < i; l++) {
				if (solution[j][i].empty() ||
					solution[j][l].size() + solution[j + l][i - l].size() 
						< solution[j][i].size())
					solution[j][i] = solution[j][l] + solution[j + l][i - l];
			}
		}
	cout << solution[0][line.size()] << "\n";	
}
