#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> correct(n), wrong(m);
	for (int i = 0; i < n; i++)
		cin >> correct[i];
	for (int i = 0; i < m; i++)
		cin >> wrong[i];
	int TL = 1;
	bool valid = true;
	while (true){
		bool extra = false;
		bool noTime = false;
		for (int i = 0; i < n; i++){
			if (correct[i] > TL){
				noTime = true;
				break;
			}
			if (correct[i] * 2 <= TL)
				extra = true;
		}
		if (noTime){
			TL++;
			continue;
		}
		for (int i = 0; i < m; i++)
			if (wrong[i] <= TL){
				valid = false;
				break;
			}
		if (!valid)
			break;
		if (extra)
			break;
		TL++;
		
	}
	if (valid)
		cout << TL << "\n";
	else
		cout << "-1\n";
}
