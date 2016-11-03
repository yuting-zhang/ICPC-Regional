#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> mem(100005, -1);

    while (T--) {
        int a, b;
        cin >> a >> b;
        int answer = 0;
        for (int i = a; i <= b; i++) {
            if (mem[i] != -1) {
                answer += mem[i];
                continue;
            }

            int num = i;
            int counter[10] = {0};

            bool good = true;
            while (num > 0) {
                int digit = num % 10; 
                if (counter[digit] != 0) {
                    good = false;
                    break;
                }
                else
                    counter[digit]++;
                num /= 10;
            }
            if (good)
                answer++;
            mem[i] = good;
        }
        cout << answer << "\n";
    }
}
