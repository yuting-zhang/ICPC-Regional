#include <bits/stdc++.h>

using namespace std;

struct node_t{
public:
    int node, length, value;
};

bool operator<(const node_t& lhs, const node_t& rhs) {
    if (lhs.length > rhs.length)
        return true;
    else if (lhs.length == rhs.length && lhs.value < rhs.value)
        return true;
    else if (lhs.length == rhs.length && lhs.value == rhs.value && lhs.node < rhs.node)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i];
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> adjList(n);
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        adjList[a].push_back({b, d});
        adjList[b].push_back({a, d});
    }

    vector<int> dist(n, 1000000000);
    vector<int> value(n, 0);

    priority_queue<node_t> pq;

    dist[0] = 0;
    value[0] = items[0];
    pq.push(node_t({0, 0, value[0]}));

    while (!pq.empty()) {
        node_t front = pq.top();
        pq.pop();
        int u = front.node;

        if (front.length > dist[front.node] || (front.length == dist[front.node] && front.value < value[front.node]))
            continue;

        for (pair<int,int> v : adjList[front.node]) {
            if (dist[u] + v.second < dist[v.first] || (dist[u] + v.second == dist[v.first] && value[u] + items[v.first] > value[v.first])) {
                dist[v.first] = dist[u] + v.second;
                value[v.first] = value[u] + items[v.first];
                pq.push(node_t({v.first, dist[v.first], value[v.first]}));
            }
        }
    }
    if (dist[n - 1] == 1000000000)
        cout << "impossible\n";
    else
        cout << dist[n - 1] << " " << value[n - 1] << "\n";
}
