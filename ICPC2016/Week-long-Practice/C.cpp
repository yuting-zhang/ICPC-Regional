#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

bool compare(const pair<long long, long long>& lhs, const pair<long long, long long>& rhs) {
    lhs.first * 2 * remain;

    if (lhs.second > rhs.second)
        return true;
    else if (lhs.second == rhs.second && lhs.first < rhs.first)
        return true;
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<pair<long long, long long> > cows(N);
    for (int i = 0; i < N; i++)
        cin >> cows[i].first >> cows[i].second;
    sort(cows.begin(), cows.end(), compare);

    long long answer = 0;
    long long totalTime = 0;
    for (int i = 0; i < cows.size(); i++) {
        const pair<long long, long long>& it = cows[i];
        answer += it.second * totalTime;
        totalTime += it.first * 2;
    }
    cout << answer << "\n";
}
