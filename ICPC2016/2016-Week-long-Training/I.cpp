#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <utility>
#include <map>
#include <queue>
#include <climits>

using namespace std;

struct node_t {
    node_t(int node, int trail, long long cost): _node(node), _trail(trail), _cost(cost) {}
    int _node, _trail;
    long long _cost;
};

bool operator<(const node_t& lhs, const node_t& rhs) {
    if (lhs._cost > rhs._cost)
        return true;
    else if (lhs._cost == rhs._cost)
        return make_pair(lhs._node, lhs._trail) > make_pair(rhs._node, rhs._trail);
    return false;
}

int main() {
    int N, T, S, E;
    scanf("%d %d %d %d", &N, &T, &S, &E);
    int counter = 0;
    map<int, int> hash;
    vector<vector<pair<int, int> > > adjList;
    adjList.push_back(vector<pair<int, int> >(N + 1));
    hash[S] = counter++;
    S = hash[S];
    if (hash.count(E) == 0) {
        adjList.push_back(vector<pair<int, int> >(N + 1));
        hash[E] = counter++;
    }
    E = hash[E];

    for (int i = 0; i < T; i++) {
        int len, I1, I2;
        scanf("%d %d %d", &len, &I1, &I2);
        if (hash.count(I1) == 0) {
            adjList.push_back(vector<pair<int, int> >(N + 1));
            hash[I1] = counter++;
        }
        if (hash.count(I2) == 0) {
            adjList.push_back(vector<pair<int, int> >(N + 1));
            hash[I2] = counter++;
        }
        adjList[hash[I1]].push_back(make_pair(hash[I2], len));
        adjList[hash[I2]].push_back(make_pair(hash[I1], len));
    }
     
    priority_queue<node_t> pq;
    vector<vector<long long> > dist(counter, vector<long long>(N + 1, INT_MAX));
    dist[S][0] = 0;
    pq.push(node_t(S, 0, 0));

    long long answer = 0;
    while (!pq.empty()) {
        node_t node = pq.top();
        pq.pop();
        int u = node._node;
        int trail = node._trail;
        long long cost = node._cost;

        if (u == E && trail == N) {
            answer = cost;
            break;
        }

        if (trail == N)
            continue;
        if (dist[u][trail] < cost)
            continue;

        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first;
            int len = adjList[u][i].second;
            if (cost + len < dist[v][trail + 1]) {
                dist[v][trail + 1] = cost + len;
                pq.push(node_t(v, trail + 1, cost + len));
            }
        }
    }
    printf("%lld\n", answer);
}
