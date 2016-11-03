#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    bool decreasing = false;
    bool seg = false;

    int index = 0;
    int s = -2, t = -1;
    while (index + 1 < n) {
        if (a[index] >= a[index + 1]) {
            if (!decreasing) {
                if (seg) {
                    s = -1;
                    break;
                }
                decreasing = true;
                s = index;
            }
        }
        else if (a[index] < a[index + 1] && decreasing) {
            seg = true;
            t = index;
            decreasing = false;
        }
        index++;
    }
    if (t == -1)
        t = n - 1;
    if (t >= 0 && t != n - 1 && a[s] > a[t + 1])
        s = -1;
    if (s > 0 && a[t] < a[s - 1])
        s = -1;
    if (s == -1)
        cout << "no\n";
    else if (s == -2)
        cout << "yes\n1 1\n";
    else
        cout << "yes\n" << s + 1 << " " << t + 1 << "\n";
}
