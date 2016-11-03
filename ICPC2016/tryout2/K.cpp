#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

long long gcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long l1, a1, l2, a2, lt, at;
        cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;

        /*
        multi = gcm(l1, a1);
        
        long long x, y;

        long long m1 = l2 * (multi / l1), m2 = a2 * (multi / a1);
        long long t1 = lt * (multi / l1), t2 = at * (multi / a1);

        if (m1 - m2 == 0) {
            if (
        }
        else {
            y = (t1 - t2) / (m1 - m2);
            x = (lt - l2 * y) / l1;
        }

        if (l1 * x + l2 * y != lt || a1 * x + a2 * y != at)
            cout << "?\n";
        else
            cout << x << " " << y << "\n";
        */
        int x = -1, y = -1;
        for (int i = 1; i <= lt; i++) {
            int j = (lt - l1 * i) / l2;
            if (j >= 1 && l1 * i + l2 * j == lt && a1 * i + a2 * j == at) {
                if (x == -1) {
                    x = i;
                    y = j;
                }
                else {
                    x = -1;
                    break;
                }
            }

        }
        if (x == -1)
            cout << "?\n";
        else
            cout << x << " " << y << "\n";
    }
}
