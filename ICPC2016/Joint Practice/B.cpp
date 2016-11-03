#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int num;
  cin >> num;
  if (num % 10 == 0)
    cout << "2\n";
  else {
    cout << "1\n";
    cout << num % 10 << "\n";
  }
  /*
    int input;
    cin >> input;
    vector<bool> dp(20000, false);
    dp[0] = false;
    for (int i = 1; i <= 20000; i++) {
        string num = to_string(i);
        vector<bool> possible(10);
        for (char digit: num)
          if (digit != '0')
            possible[digit - '0'] = 1;
        for (int j = 0; j < 10; j++)
          if (possible[j]) {
            if (i - j >= 0)
              if (!dp[i - j])
                dp[i] = true;
          }
    }

    for (int i = 0; i < 100; i++)
      cout << i << " " << dp[i] << "\n";
    if (dp[input])
      cout << "1\n";
    else
      cout << "2\n";
      */
}
