#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

bool DPS(int curr, int end, vector<bool>& visited, const vector<vector<int>>& stations, vector<int>& result){
	visited[curr] = true;
	result.push_back(curr);

	if (curr == end)
		return true;

	for (int i = 0; i < stations[curr].size(); i++)
		if (visited[stations[curr][i]] == false)
			if (DPS(stations[curr][i], end, visited, stations, result))
				return true;
	
	visited[curr] = false;
	result.pop_back();
	return false;
}

int main(){
	int N;
	scanf("%d\n", &N);
	map<string, int> names;
	vector<string> num_to_name;
	int count = 0;

	vector<vector<int>> stations;

	for (int i = 0; i < N; i++){
		string line;
		getline(cin, line);
		istringstream sin(line);
		string name;
		bool first = true;
		int center;
		while (sin >> name){
			if (names.find(name) == names.end()){
				names[name] = count++;
				stations.push_back(vector<int>());
				num_to_name.push_back(name);
			}
			if (first){
				center= names[name];
				first = false;
			}
			else{
				stations[center].push_back(names[name]);
				stations[names[name]].push_back(center);
			}
		}
	}

	string startname, endname;
	cin >> startname >> endname;
	if (names.find(startname) == names.end())
		names[startname] = count++;
	if (names.find(endname) == names.end())
		names[endname] = count++;
	int start = names[startname], end = names[endname];

	vector<int> result;
	vector<bool> visited(count, false);

	if (DPS(start, end, visited, stations, result)){
		bool first = true;
		for (int i = 0; i < result.size(); i++)
			if (first){
				cout << num_to_name[result[i]];
				first = false;
			}
			else
			 	cout << " " << num_to_name[result[i]];
		cout << "\n";
	}
	else
		cout << "no route found\n";
}
