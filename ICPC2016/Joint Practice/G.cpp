#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <exception>

using namespace std;

struct triple {
    triple(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }
    int x, y, z;
};

bool operator<(const triple& lhs, const triple& rhs) {
    if (lhs.x < rhs.x)
        return true;
    else if (lhs.x == rhs.x && lhs.y < rhs.y)
        return true;
    else if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z < rhs.z)
        return true;
    return false;
}

struct node_t {
    node_t(int prev, int curr, double dist, double angle): _prev(prev), _curr(curr), _dist(dist), _angle(angle) {}
    int _prev, _curr;
    double _dist;
    double _angle;
};

bool operator<(const node_t& lhs, const node_t & rhs) {
    if (lhs._angle > rhs._angle)
        return true;
    else if (lhs._angle == rhs._angle && lhs._dist > rhs._dist)
        return true;
    else if (lhs._angle == rhs._angle && lhs._dist == rhs._dist)
        return make_pair(lhs._prev, lhs._curr) > make_pair(rhs._prev, rhs._curr);
    return false;
}

double norm(int x, int y) {
    return sqrt(x * x + y * y);
}

double getAngle(int x1, int y1, int x2, int y2) {
    if (x1 == 0 && y1 == 0)
        return 0;
    if (x2 == 0 && y2 == 0)
        return 0;

    double dotProduct = x1 * x2 + y1 * y2;   
    double cosAngle = dotProduct / norm(x1, y1) / norm(x2, y2);
    double retval = 180.0 - acos(cosAngle) * 180.0 / acos(-1);
    return retval;
}

double eDist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    int J, R ,D;
    scanf("%d %d %d", &J, &R, &D);
    vector<pair<int, int>> position(J);
    for (int i = 0; i < J; i++) 
        scanf("%d %d", &position[i].first, &position[i].second);

    vector<vector<pair<int, double>>> adjList(J);
    for (int i = 0; i < R; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjList[u - 1].push_back({v - 1, eDist(position[u - 1], position[v - 1])});
    }

    map<triple, double> angles;
    for (int i = 0; i < J; i++)
        for (int j = 0; j < J; j++)
            for (int k = 0; k < J; k++) {
                angles[triple(i, j, k)] = getAngle(position[i].first - position[j].first, position[i].second - position[j].second,
                                                   position[k].first - position[j].first, position[k].second - position[j].second);
            }
    
    map<pair<int, int>, pair<double, double>> dist;
    dist[make_pair(0, 0)] = {0, 0};

    priority_queue<node_t> pq;
    pq.push(node_t(0, 0, 0, 0));

    bool found = false;
    double answer = 0;
    while (!pq.empty()) {
        node_t node = pq.top();
        pq.pop();
        if (node._curr == J - 1) {
            found = true;
            answer = node._angle;
            break;
        }

        for (auto nextNode: adjList[node._curr]) {
            int dest = nextNode.first;
            double roadDist = nextNode.second;

            double angle = angles[triple(node._prev, node._curr, dest)];

            if (node._dist + roadDist <= D) {
                if (dist.count(make_pair(node._curr, dest)) == 0 ||
                        (max(node._angle , angle) < dist[make_pair(node._curr, dest)].second)) {
                    dist[make_pair(node._curr, dest)] = {node._dist + roadDist, max(node._angle, angle)};
                }
                pq.push(node_t(node._curr, dest, node._dist + roadDist, max(node._angle, angle)));
            }
        }
    }
    if (found)
        printf("%.10f\n", answer);
    else
        printf("Impossible\n");
}
