#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 1; i <= N; i++) 
        for (int j = i; j <= N; j++) {
            if (i * j > N)
                break;
            answer++;
        }
    cout << answer << "\n";
}
