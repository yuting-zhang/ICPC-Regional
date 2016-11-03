#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> votes(n);
	int threshold = 0, total = 0;
	for (int i = 0; i < n; i++){
		cin >> votes[i];
		threshold = max(threshold, votes[i]);
		total += votes[i];
	}

	int candy = INT_MAX;
	while (threshold){
		int steal = 0;
		for (int j = 1; j < votes.size(); j++)
			if (votes[j] > threshold)
				steal += votes[j] - threshold;
		int rest = total - steal;
		if (votes[0] + steal <= threshold){
			if (threshold + 1 - (votes[0] + steal) <= rest){
				steal += threshold + 1 - (votes[0] + steal);
			}
			else 
				steal = -1;
	 	}
		if (steal != -1)
			candy = min(candy, steal);
		threshold--;
	}
	cout  << candy << "\n";	
}
