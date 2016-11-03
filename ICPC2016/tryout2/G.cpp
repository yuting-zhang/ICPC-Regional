#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    unsigned long long answer = 1;
    int digit = 1;
    unsigned long long front = 1;
    long long hid = 0;
    while (true) {
        front = front * answer;

        digit = to_string(front).size() + hid;
        if (digit >= line.size())
            break;

        while (front >= 100000000000000) {
            hid += 1;
            front = front / 10;
        }
        answer += 1;
    }

    cout << (long long)answer << "\n";
}
