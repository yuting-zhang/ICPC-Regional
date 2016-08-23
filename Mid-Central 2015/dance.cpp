#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int R;
	while (cin >> R){
		vector<vector<bool>> routines(R, vector<bool>(26, false));
		for (int i = 0; i < R; i++){
			string routine;
			cin >> routine;
			for (char ch : routine)
				routines[i][ch - 'A'] = true;
		}

		vector<vector<int>> quick(R, vector<int>(R, 0));

		for (int i = 0; i < R; i++)
			for (int j = i + 1; j < R; j++){
				int counter = 0;
				for (int k = 0; k < 26; k++)
					if (routines[i][k] && routines[j][k])
						counter++;
				quick[i][j] = quick[j][i] = counter;
			}

		vector<int> state(R);
		for (int i = 0; i < R; i++)
			state[i] = i;

		int best = R * 26;
		do{
			int curr = 0;
			for (int i = 0; i < R - 1; i++)
				curr += quick[state[i]][state[i + 1]];
			best = min(best, curr);
		}while (next_permutation(state.begin(), state.end()));
		cout << best << "\n";
	}
}
