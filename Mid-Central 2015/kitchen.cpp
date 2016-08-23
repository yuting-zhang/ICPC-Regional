#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>
#include <unordered_map>
#include <climits>

using namespace std;

inline unsigned encode(int n, vector<int> state){
	unsigned retval = 0;
	for (int i = 0; i < n - 1; i++)
		retval += (state[i] << 7 * i);
	return retval;
}

inline vector<int> decode(int n, int total, unsigned state){
	vector<int> retval(n);
	for (int i = 0; i < n - 1; i++){
		retval[i] = ((state >> 7 * i) & 0x7f);
		total -= retval[i];
	}
	retval[n - 1] = total;
	return retval;
}

int main(){
	int n;
	while (cin >> n){
		vector<int> cup(n);
		for (int i = 0; i < n; i++)
			cin >> cup[i];
		int V;
		cin >> V;

		priority_queue<pair<int, unsigned>, vector<pair<int, unsigned>>, greater<pair<int, unsigned>>> pq;
		unordered_map<unsigned, int> dist;

		vector<int> state(n);
		state[0] = cup[0];
		pq.push({0, encode(n, state)});
		dist[encode(n, state)] = 0;

		int answer = INT_MAX;
		while (!pq.empty()){
			auto front = pq.top();
			pq.pop();
			int pour = front.first;
			if (pour > dist[front.second])
				continue;

			state  = decode(n, cup[0], front.second);

			if (state[0] == V){
				answer = pour;
				break;
			}

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (i != j){
						vector<int> new_state = state;
						int water = min(state[i], cup[j] - state[j]);
						new_state[i] = state[i] - water;
						new_state[j] = state[j] + water;
						int new_dist = water + pour;

						int encoded = encode(n, new_state);
						if (dist.find(encoded) == dist.end() || new_dist < dist[encoded]){
							dist[encoded] = new_dist;	
							pq.push({new_dist, encoded});
						}
					}
		}

		if (answer == INT_MAX)
			cout << "impossible\n";
		else
			cout << answer << "\n";
	}
	return 0;
}
