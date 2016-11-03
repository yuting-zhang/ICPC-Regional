#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "1") {
            printf("1\n");
            continue;
        }
        vector<int> bigInteger(line.size() + 1);                
        for (int i = 0; i < line.size(); i++)
            bigInteger[i] = line[line.size() - 1 - i] - '0';

        for (int i = 0; i < line.size(); i++)
            bigInteger[i] *= 2;

        for (int i = 0; i < line.size(); i++) {
            bigInteger[i + 1] += bigInteger[i] / 10;
            bigInteger[i] %= 10;
        }
        bigInteger[0] -= 2;
        for (int i = 0; i < line.size(); i++) {
            if (bigInteger[i] < 0) {
                bigInteger[i] += 10;
                bigInteger[i + 1] -= 1;
            }
        }
        if (bigInteger[line.size()] != 0)
            printf("%d", bigInteger[line.size()]);
        for (int i = line.size() - 1; i >= 0; i--)
            printf("%d", bigInteger[i]);
        printf("\n");
    }
}

