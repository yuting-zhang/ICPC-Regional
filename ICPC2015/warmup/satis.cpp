#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool get_state(unsigned long long state, int number){
	bool negate = false;
	if (number < 0){
		negate = true;
		number = -number;
	}
	number--;
	bool ret = state & (1 << number);
	if (negate)
		ret = !ret;
	return ret;
}
int main(){
	int tc;
	scanf("%d\n", &tc);
	while (tc--){
		int n, m;
		scanf("%d %d\n", &n, &m);
		string line;
		vector<vector<int>> clause(m);
	
		for (int i = 0; i < m; i++){
			getline(cin, line);
			string word;
			istringstream sin(line);
			while (sin >> word){

				bool negate = false;
				if (word[0] == '~'){
					negate = true;
					word = word.substr(2);
				}
				else
					word = word.substr(1);
				
				int number = stoi(word);
				number;
				if (negate)
					clause[i].push_back(-number);
				else 
					clause[i].push_back(number);
				sin >> word;
			}
		}

		/*for (int i = 0; i < clause.size(); i++){
			for (int j = 0; j < clause[i].size(); j++)
				cout << clause[i][j] << " ";
			cout << "\n";
		}
		*/
		unsigned long long state = 0;
		bool satis = true;
		while (state < (1 << n)){
			satis = true;
			for (int i = 0; satis && i < clause.size(); i++){
				bool curr = get_state(state, clause[i][0]);
				for (int j = 1; satis && j < clause[i].size(); j++)
					curr |= get_state(state, clause[i][j]);
				if (!curr){
					satis = false;
				}
			}
			if (satis)
				break;
			state++;
		}
		if (satis)
			printf("satisfiable\n");
		else
			printf("unsatisfiable\n");
	}
}
