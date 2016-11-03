#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int m = 1, digit = 1;

        while ((m = m % n) != 0) {
            m = m * 10 + 1;
            digit++;
        }
        printf("%d\n", digit); 
    }
}
