#include <iostream>

using namespace std;

int main() {
    unsigned long long n, m;
    cin >> n;
    m = 1;
    while (n % m == 0)
        m *= 3;
    cout << n / m + 1 << "\n";
}
