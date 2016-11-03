#include <bits/stdc++.h>

using namespace std;

string digits[10][5] = {
    {"***", "* *", "* *", "* *", "***"},
    {"  *", "  *", "  *", "  *", "  *"},
    {"***", "  *", "***", "*  ", "***"},
    {"***", "  *", "***", "  *", "***"},
    {"* *", "* *", "***", "  *", "  *"},
    {"***", "*  ", "***", "  *", "***"},
    {"***", "*  ", "***", "* *", "***"},
    {"***", "  *", "  *", "  *", "  *"},
    {"***", "* *", "***", "* *", "***"},
    {"***", "* *", "***", "  *", "***"},
};

int main() {
    string line;
    char digit[10][5][3];
    memset(digit, 0, sizeof digit);

    int n = 0;
    for (int i = 0; i < 5; i++) {
        getline(cin, line);
        n = (line.size() + 1) / 4;

        int index = 0;
        int num = 0;
        while (index < line.size()) {
            digit[num][i][0] = line[index];
            digit[num][i][1] = line[index + 1];
            digit[num][i][2] = line[index + 2];
            index += 4;
            num++;
        }
    }

    int value = 0;
    for (int i = 0; i < n; i++) {
        bool found = false; 
        for (int j = 0; j <= 9 && !found; j++) {
            bool good = true;
            for (int r = 0; r < 5 && good; r++)
                for (int c = 0; c < 3 && good; c++)
                    if (digit[i][r][c] != digits[j][r][c])
                        good = false;
            if (good) {
                found = true;
                value = value * 10 + j;
            }
        }
        if (!found) {
            value = 1;
            break;
        }
    }
    if (value % 6 == 0)
        cout << "BEER!!\n";
    else
        cout << "BOOM!!\n";
}
