#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	string word;
	long long K;

	long long fact[20] = {1};
	for (int i = 1; i < 20; i++)
		fact[i] = fact[i - 1] * i;

	while (cin >> word >> K && word != "#") {
		sort(word.begin(), word.end());
		
		int count[26] = {0};
		long long skip = fact[word.size() - 1];

		for (int i = 0; i < word.size(); i++) 
			count[word[i] - 'A']++;

		for (int i = 0; i < 26; i++)
			if (count[i])
				skip /= fact[count[i]];

		int digit = 0;
		
		string answer;
		while (digit < word.size()) {
			for (int i = 0; i < 26; i++)
				if (count[i]) {

					count[i]--;

					skip = fact[word.size() - 1 - digit];
					for (int i = 0; i < 26; i++)
						if (count[i])
							skip /= fact[count[i]];

					if (skip < K) {
						K -= skip;
						count[i]++;
					}
					else {
						answer += ('A' + i);
						break;
					}
				}

			digit++;

		}
		cout << answer << "\n";
	}
}
