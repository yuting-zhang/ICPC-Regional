#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string pw, msg;
	while (cin >> pw >> msg){
		vector<int> letter(26, 0);
		for (char ch : pw)
			letter[ch - 'A']++;

		int index = 0;
		bool good = true;
		for (char ch : msg){
			if (letter[ch - 'A'] > 0){
				if (pw[index] != ch){
					good = false;
					break;
				}
				else{
					letter[ch - 'A']--;
					index++;
				}
			}
		}
		if (index != pw.size())
			good = false;
		cout << (good ? "PASS" : "FAIL") << "\n";
	}
}
