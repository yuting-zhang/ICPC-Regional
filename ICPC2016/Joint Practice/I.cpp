#include <iostream>

using namespace std;

int main() {
    unsigned long long x;
    while (cin >> x && x) {
        unsigned long long answer = 11111111111111111111LLU;
        while (answer >= 1) {
        if (x % answer == 0) {
            cout << x / answer << "\n";
            break;
        }
        else
            answer /= 10;
        }
    }
}
