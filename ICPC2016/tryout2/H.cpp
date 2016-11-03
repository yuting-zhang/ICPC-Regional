#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, B;
    cin >> H;
    vector<int> hotdog(H);

    for (int i = 0; i < H; i++)
        cin >> hotdog[i];

    cin >> B;
    vector<int> bun(B);
    for (int i = 0; i < B; i++)
        cin >> bun[i];

    vector<int> dp1(100010, 1000000000);
    dp1[0] = 0;
    for (int j = H - 1; j >= 0; j--)
        for (int i = 100000; i >= 1; i--) {
            if (i - hotdog[j] >= 0)
                if (dp1[i - hotdog[j]] + 1 < dp1[i])
                    dp1[i] = dp1[i - hotdog[j]] + 1;
        }

    vector<int> dp2(100010, 1000000000);
    dp2[0] = 0;
    for (int j = B - 1; j >= 0; j--)
        for (int i = 100000; i >= 1; i--) {
            if (i - bun[j] >= 0)
                if (dp2[i - bun[j]] + 1 < dp2[i])
                    dp2[i] = dp2[i - bun[j]] + 1;
        }


    int answer = 1000000000;
    for (int i = 1; i <= 100000; i++)
        if (dp1[i] + dp2[i] < answer) {
            answer = dp1[i] + dp2[i];
        }

    if (answer == 1000000000)
        cout << "impossible\n";
    else
        cout << answer << "\n";
}
