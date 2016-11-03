#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    bool np = true;

    unordered_map<int, vector<int>> adjList, rAdjList;

    vector<int> order(N);

    for (int i = 0; i < N; i++) {
        int id, m;
        cin >> id >> m;
        order[i] = id;
        while (m--) {
            int next;
            cin >> next;
            adjList[id].push_back(next);
            rAdjList[next].push_back(id);
        }
    }

    vector<bool> visited(1100, false);
    visited[0] = true;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : rAdjList[u])
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
    }

    for (int i = 0; i < N; i++)
        if (!visited[order[i]]) {
            cout << "TRAPPED " << order[i] << "\n";
            np = false;
        }

    visited.assign(1100, false);
    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adjList[u])
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
    }

    for (int i = 0; i < N; i++)
        if (!visited[order[i]]) {
            cout << "UNREACHABLE " << order[i] << "\n";
            np = false;
        }

    if (np)
        cout << "NO PROBLEMS\n";
}
