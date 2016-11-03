#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int building[N];
        for (int i = 0; i < N; i++)
            scanf("%d", &building[i]);
        
        vector<int> left(N, 1), right(N, 1);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < i; j++)
                if (building[j] < building[i] && left[j] + 1 > left[i])
                    left[i] = left[j] + 1;
        for (int i = N - 1; i >= 0; i--)
            for (int j = N - 1; j > i; j--)
                if (building[j] < building[i] && right[j] + 1 > right[i])
                    right[i] = right[j] + 1;
        int answer = 0;
        for (int i = 0; i < N; i++)
            answer = max(answer, left[i] + right[i]);
        printf("%d\n", answer - 1);
    }
}
