#include <bits/stdc++.h>

using namespace std;

int main () {
    string line;
    cin >> line;
    int day = 0;
    for (int i = 0; i < line.size(); i++) {
        line[i] = toupper(line[i]);
        if (i % 3 == 0 && line[i] != 'P')
            day++;
        if (i % 3 == 1 && line[i] != 'E')
            day++;
        if (i % 3 == 2 && line[i] != 'R')
            day++;
    }
    cout << day << "\n";
}
