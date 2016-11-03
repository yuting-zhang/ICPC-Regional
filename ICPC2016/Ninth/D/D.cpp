#include <iostream>

using namespace std;

int main(){
	int w;
	cin >> w;
	if (w <= 3)
		cout << "NO\n";
	else 
		cout << (w % 2 ? "NO" : "YES") << "\n";
}
