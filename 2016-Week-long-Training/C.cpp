#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const pair<long long, long long>& lhs, const pair<long long, long long>& rhs) {
    double l = lhs.second * 1.0 / lhs.first;
    double r = rhs.second * 1.0 / rhs.first;
    return l < r;
}

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long> > cows(N);
    for (int i = 0; i < N; i++)
        cin >> cows[i].first >> cows[i].second;
    sort(cows.rbegin(), cows.rend(), compare);

    long long answer = 0;
    long long total_time = 0;

    for (int i = 0; i < N; i++) {
        answer += total_time * cows[i].second;
        total_time += cows[i].first * 2;
    }

    cout << answer << "\n";
}
