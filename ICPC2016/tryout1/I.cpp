#include <bits/stdc++.h>

using namespace std;

int main() {
    string pattern;
    cin >> pattern;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
         
        bool dp[line.size() + 1][pattern.size() + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = true;
        if (pattern[0] == '*') 
            for (int j = 0; j <= line.size(); j++) 
                dp[j][1] = true;

        for (int k = 1; k <= line.size(); k++) 
            for (int j = 1; j <= pattern.size(); j++)
                if (dp[k - 1][j - 1] && pattern[j - 1] == line[k - 1])
                    dp[k][j] = true;
                else if (pattern[j - 1] == '*' && (dp[k][j - 1] || dp[k - 1][j] || dp[k - 1][j - 1]))
                    dp[k][j] = true;
                //else if (dp[j - 1][k] && j > 1 && pattern[j - 2] == '*')
                 //   dp[k][j] = true;
                
        if (dp[line.size()][pattern.size()])
            cout << line << "\n";
/*        for (int i = 0; i <= line.size(); i++)
            for (int j = 0; j <= pattern.size(); j++)
                cout << i << " " << j << " " << dp[i][j] << "\n";*/
    }
}
