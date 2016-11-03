#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, string> hash;
    hash['a'] = "2";
    hash['b'] = "22";
    hash['c'] = "222";
    hash['d'] = "3";
    hash['e'] = "33";
    hash['f'] = "333";
    hash['g'] = "4";
    hash['h'] = "44";
    hash['i'] = "444";
    hash['j'] = "5";
    hash['k'] = "55";
    hash['l'] = "555";
    hash['m'] = "6";
    hash['n'] = "66";
    hash['o'] = "666";
    hash['p'] = "7";
    hash['q'] = "77";
    hash['r'] = "777";
    hash['s'] = "7777";
    hash['t'] = "8";
    hash['u'] = "88";
    hash['v'] = "888";
    hash['w'] = "9";
    hash['x'] = "99";
    hash['y'] = "999";
    hash['z'] = "9999";
    hash[' '] = "0";
    int n;
    string line;
    cin >> n;
    getline(cin, line);
    int no = 0;
    while (getline(cin, line)) {
        no++;
        string answer;
        for (int i = 0; i < line.size(); i++) {
            if (i && hash[line[i]][0] == hash[line[i - 1]][0])
                answer += ' ';
            answer += hash[line[i]];
        }
        cout << "Case #" << no << ": " << answer << "\n";
    }
}
