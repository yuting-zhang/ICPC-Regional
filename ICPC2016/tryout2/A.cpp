#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<char, string> hash;
    hash['a'] = "@";
    hash['b'] = "8";
    hash['c'] = "(";
    hash['d'] = "|)";
    hash['e'] = "3";
    hash['f'] = "#";
    hash['g'] = "6";
    hash['h'] = "[-]";
    hash['i'] = "|";
    hash['j'] = "_|";
    hash['k'] = "|<";
    hash['l'] = "1";
    hash['m'] = "[]\\/[]";
    hash['n'] = "[]\\[]";
    hash['o'] = "0";
    hash['p'] = "|D";
    hash['q'] = "(,)";
    hash['r'] = "|Z";
    hash['s'] = "$";
    hash['t'] = "']['";
    hash['u'] = "|_|";
    hash['v'] = "\\/";
    hash['w'] = "\\/\\/";
    hash['x'] = "}{";
    hash['y'] = "`/";
    hash['z'] = "2";

    string st;
    getline(cin, st);
    string answer;
    for (int i = 0; i < st.size(); i++) {
        st[i] = tolower(st[i]);
        if (hash.count(st[i]))
            answer += hash[st[i]];
        else
            answer += st[i];
    }
    cout << answer << "\n";
}
