/*
1 
1 
1 3
1 3
1 3 5 2 4
1 3 5 2 4 6
*/

#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	if (N == 1 || N == 2)
		cout << "1\n1\n";
	else if (N == 3)
		cout << "2\n1 3\n";
	else if (N == 4)
		cout << "4\n2 4 1 3\n";
	else{
		cout << N << "\n";
		for (int i = 0; i < (N + 1) / 2; i++)
			cout << (i * 2 + 1) << " ";
		for (int i = 0; i < N / 2 - 1; i++)
			cout << (i + 1) * 2 << " ";
		cout << (N / 2) * 2 << "\n";
	}
}
