#include <iostream>
#include <cstdio>

using namespace std;

int getLCM(int a, int b){
	if (a > b){
		int t = a;
		a = b;
		b = t;
	}
	int ret = b;
	while (ret % a != 0)
		ret += b;
	return ret;
}

int main(){
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	int lcm = getLCM(x, y);
	int s = a / lcm;
	int t = b / lcm;
	int answer = t - s;
	if (a % lcm == 0)
		answer++;
	cout << answer << "\n";
}
