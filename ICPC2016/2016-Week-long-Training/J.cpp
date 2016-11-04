#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <map>
#include <climits>

using namespace std;

int main() {
    map<char, map<char, int> > score;
    score['A']['A'] = 5;
    score['A']['C'] = -1;
    score['C']['A'] = -1;
    score['A']['G'] = -2;
    score['G']['A'] = -2;
    score['A']['T'] = -1;
    score['T']['A'] = -1;
    score['A']['-'] = -3;
    score['-']['A'] = -3;
    score['C']['C'] = 5;
    score['C']['G'] = -3;
    score['G']['C'] = -3;
    score['C']['T'] = -2;
    score['T']['C'] = -2;
    score['C']['-'] = -4;
    score['-']['C'] = -4;
    score['G']['G'] = 5;
    score['G']['T'] = -2;
    score['T']['G'] = -2;
    score['G']['-'] = -2;
    score['-']['G'] = -2;
    score['T']['T'] = 5;
    score['T']['-'] = -1;
    score['-']['T'] = -1;

    int T;
    cin >> T;
    while (T--) {
        int len1, len2;
        string gene1, gene2;
        cin >> len1 >> gene1 >> len2 >> gene2;
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, INT_MIN / 2));
        dp[0][0] = 0;

        for (int i = 0; i <= len1; i++)
            for (int j = 0; j <= len2; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                    dp[i][j] = score['-'][gene2[j - 1]] + dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = score[gene1[i - 1]]['-'] + dp[i - 1][j];
                else {
                    dp[i][j] = score[gene1[i - 1]][gene2[j - 1]] + dp[i - 1][j - 1];
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + score['-'][gene2[j - 1]]);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + score[gene1[i - 1]]['-']);
                }
            }
        cout << dp[len1][len2] << "\n";
    }
}
