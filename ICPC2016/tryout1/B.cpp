#include <bits/stdc++.h>

using namespace std;

int c, l;
vector<vector<int>> adjList;

vector<int> S, visited;

vector<vector<int>> SCCs;

vector<int> far;
int dfsNumberCounter, numSCC;

void findSCC(int u) {
    visited[u] = true;

    queue<pair<int,int>> q;

    visited[u] = true;
    q.push({u, 0});

    vector<int> SCC;
    int dist = 0;
    int v = u;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        SCC.push_back(front.first);

        if (front.second > dist) {
            dist = front.second;
            v = front.first;
        }

        for (int node : adjList[front.first]) {
            if (!visited[node]) {
                visited[node] = true;
                q.push({node, front.second + 1});
            }
        }
    }

    SCCs.push_back(SCC);
    numSCC++;
    far.push_back(v);
}


int getDiameter(int v) {
    queue<pair<int,int>> q;
    int answer = 0;
    visited.assign(c, false);
    visited[v] = true;
    q.push({v, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        if (front.second > answer) {
            answer = front.second;
        }

        for (int node : adjList[front.first]) {
            if (!visited[node]) {
                visited[node] = true;
                q.push({node, front.second + 1});
            }
        }
    }
    return answer;
}

int main() {
    scanf("%d %d", &c, &l);
    adjList.assign(c, vector<int>());
    for (int i = 0; i < l; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    visited.assign(c, 0);

    far.assign(c, 0);
    dfsNumberCounter = numSCC = 0;

    for (int i = 0; i < c; i++)
        if (!visited[i])
            findSCC(i);

    vector<int> diameter(numSCC);

    int first = 0, second = 0;
    for (int i = 0; i < numSCC; i++) {
        diameter[i] = getDiameter(far[i]);
        if (diameter[i] % 2 == 0)
            diameter[i] /= 2;
        else
            diameter[i] = (diameter[i] + 1) / 2;
        if (diameter[i] >= first) {
            second = first;
            first = diameter[i];
        }
        else if (diameter[i] > second)
            second = diameter[i];
    }

    if (diameter.size() == 1)
        cout << first << "\n";
    else
        cout << first + second + 1 << "\n";
}
