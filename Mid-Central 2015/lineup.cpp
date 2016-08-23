#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n;
	while (cin >> n){
		bool increasing = true, decreasing = true;
		vector<string> names(n);
		for (int i = 0; i < n; i++)
			cin >> names[i];

		for (int i = 0; i < n - 1; i++)
			if (names[i + 1] > names[i])
				decreasing = false;
			else if (names[i + 1] < names[i])
				increasing = false;

		if (increasing)
			cout << "INCREASING\n";
		else if (decreasing)
			cout << "DECREASING\n";
		else
			cout << "NEITHER\n";
	}
}
