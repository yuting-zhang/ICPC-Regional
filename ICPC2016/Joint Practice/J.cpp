#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string line;
    while (cin >> line) {
        vector<int> sim(26, 0);
        for (char ch: line)
            sim[ch - 'a']++;
        sort(sim.begin(), sim.end());
        int index = 0;
        while (sim[index] == 0 && index < sim.size())
            index++;
        int answer = 0;
        while (index + 2 < sim.size()) {
            answer += sim[index];
            index++;
        }
        cout << answer << "\n";
    }
}
