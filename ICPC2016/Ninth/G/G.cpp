#include <string>
#include <stack>
#include <utility>
#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	string line;
	getline(cin, line);
	getline(cin, line);
	for (int tc = 0; tc < T; tc++){
		
		stack<pair<string, int>> stk;
		while (getline(cin, line) && !line.empty()){
			while (!stk.empty()){
				auto front = stk.top();
				bool ok = true;
				for (int i = 0; i < front.second; i++)
					if (line[i] != front.first[i]){
						ok = false;
						break;
					}
				if (!ok){
					stk.pop();
					continue;
				}
				for (int i = 0; i < front.second; i++)
					cout << " ";
				cout << line << "\n";
				stk.push({line, front.second + 1});
				break;
			}

			if (stk.empty()){
				cout << line << "\n";
				stk.push({line, 1});
			}
		}
		cout << "\n";
	}

}
