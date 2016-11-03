#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool mount(long long n){
	bool top = false;
	int prev = n % 10;
	n /= 10;
	while (n > 0){
		int x = n % 10;
		n /= 10;
		if (x < prev && !top)
			top = true;
		else if (x > prev && top)
			return false;
		prev = x;
	}
	return true;
}

vector<int> convertVec(long long n){
	vector<int> ret;
	whie (n > 0){
		ret.push_back(n % 10);
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
}
int main(){
	long long n;
	scanf("%lld", &n);
	if (!mount(n)){
		cout << "-1\n";
		return 0;
	}

	long long answer = 0;
	vector<int> vec = convertVec(n);
	for (int i = 0; i < vec.size(); i++){
		long long curr = vec[0]
	}


	return 0;
}
