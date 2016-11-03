#include <cmath>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> angles;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        double angle = atan2(y, x);
        angle = angle * 180 / acos(-1);
        if (angle < 0)
            angle += 360;
        angles.push_back(angle);
    }

    double maxAngle = 0;
    sort(angles.begin(), angles.end());

    for (int i = 0; i < n - 1; i++)
        maxAngle = max(maxAngle, angles[i + 1] - angles[i]);

    maxAngle = max(maxAngle, angles.front() + 360 - angles.back());

    printf("%.15f\n", 360 - maxAngle);
}
