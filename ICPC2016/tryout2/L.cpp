#include <bits/stdc++.h>

using namespace std;

struct vec {
    double x, y;
};

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

struct point{
    double x, y;
};

vec toVec(point a, point b) {
    return vec({b.x - a.x, b.y - a.y});
}


bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool isConvec(const vector<point> &P) {
    int sz = P.size();
    if (sz <= 3) return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < sz-1; i++) {
        if (ccw(P[i], P[i + 1], P[(i + 2) == sz ? 1 : i + 2]) != isLeft)
            return false;
    }
    return true;
}

double area(const vector<point> &P) {
    double result = 0, x1, x2, y1, y2;
    for (int i = 0; i < P.size() - 1; i++) {
        x1 = P[i].x; x2= P[i + 1].x;
        y1 = P[i].y; y2 = P[i + 1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

#define eps  10e-5

bool intersect(point p1, point p2, point p3, point p4) {
    return (ccw(p1, p2, p3) != ccw(p1, p2 ,p4)) && (ccw(p3, p4, p1) != ccw(p3, p4, p2));
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p,q),toVec(p,r))) < eps;
}

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        vector<point> darts(7);
        for (int i = 0; i < 7; i++)
            cin >> darts[i].x >> darts[i].y;

        double bob;
        cin >> bob;
        vector<vector<int>> answer;

        vector<int> state = {0,1,2,3,4,5,6};
        do {
            double p = 0;
            vector<point> points(8);
            for (int i = 0; i < 7; i++)
                points[i] = darts[state[i]];
            points[7] = points[0];

            for (int i = 1; i < 8; i++)
                for (int j = 1; j < i - 1; j++) {
                    if (intersect(points[i - 1], points[i], points[j - 1], points[j]))
                        p = 1;
                    if (collinear(points[i - 1], points[i], points[j]) && collinear(points[i - 1], points[i], points[j - 1])) {
                        if ((dist(points[i - 1], points[i]) > dist(points[i - 1], points[j - 1]) && 
                            dist(points[j - 1], points[j]) > dist(points[j - 1], points[i - 1]) ||
                            dist(points[i - 1], points[i]) > dist(points[i - 1], points[j]) &&
                            dist(points[j - 1], points[j]) > dist(points[j], points[i - 1])))
                                p = 1;
                    }

            if (p > 0)
                continue;

            double A = area(points);

            p = A / 4.0;
            p = p * p * p;

            if (fabs(p - bob) <= 0.00001)
                answer.push_back(state);
        } while (next_permutation(state.begin(), state.end()));

        sort(answer.begin(), answer.end());
        for (int i = 0; i < 6; i++)
            cout << answer[0][i] + 1 << " ";
        cout << answer[0][6] + 1 << "\n";
    }
}
