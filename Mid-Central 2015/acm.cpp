#include <iostream>
#include <vector>

using namespace std;

int main(){
	while (true){
		vector<int> score(26, -1);
		vector<int> punish(26, 0);
		int m;
		char ch;
		string verdict;
		while (cin >> m){
			if (m == -1)
				break;
			cin >> ch >> verdict;
			if (score[ch - 'A'] == -1){
				if (verdict == "right")
					score[ch - 'A'] = m;
				else
					punish[ch - 'A']++;
			}
		}
		if (!cin)
			break;
		int solved = 0, total = 0;
		for (int i = 0; i < 26; i++)
			if (score[i] >= 0){
				solved++;
				total += score[i] + punish[i] * 20;
			}
		cout << solved << " " << total << "\n";
	}
	return 0;
}
