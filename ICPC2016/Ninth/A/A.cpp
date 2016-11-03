#include <string>
#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	while (N--){
		string word;
		cin >> word;
		if (word.size() <= 10)
			cout << word << "\n";
		else
			cout << word[0] << word.size() - 2 << word[word.size() - 1] << "\n";
	}
}
