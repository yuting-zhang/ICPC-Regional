#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	while (cin){
		int L;
		vector<bool> tubes(300001, false);
		while (cin >> L && L != -1)
			tubes[L] = true;
		if (!cin)
			break;

		for (unsigned i = 1; i <= 250000; i++){
			if (!tubes[i])
				continue;
			int counter = 0;

			for (int j = 0; j < 18; j++)
				for (int k = j; k < 18; k++){
					unsigned tube = (i ^ ((1 << j) | (1 << k)));
					if (tube > i && tubes[tube])
						counter++;
				}
			cout << i << ":" << counter << "\n";
		}
	}
	return 0;
}
