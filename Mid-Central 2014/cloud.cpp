#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int W, N, clouds = 0;
	while (cin >> W >> N && W && N) {
		clouds++;
		int cMax = 0;
		vector<pair<int, int>> words(N); // first: length of word; second: occurrence
		for (int i = 0; i < N; i++) {
			string word;
			cin >> word >> words[i].second;
			words[i].first = word.size();
			cMax = max(cMax, words[i].second);
		}

		vector<int> fontSize(N);
		for (int i = 0; i < N; i++)
			fontSize[i] = 8 + ceil((40.0 * (words[i].second - 4)) / (cMax - 4));

		int height = 0, currWidth = 0, currHeight = 0;

		for (int i = 0; i < N; i++) {
			int width = ceil(9.0 / 16 * fontSize[i] * words[i].first);

			// Start a new row.
			if (i == 0 || width + currWidth + 10 > W) {
				height += currHeight;
				currWidth = width;
				currHeight = fontSize[i];
			}
			// Continue on this row.
			else {
				currWidth += width + 10;
				currHeight = max(currHeight, fontSize[i]);
			}
		}

		height += currHeight;
		printf("CLOUD %d: %d\n", clouds, height);	
	}
}
