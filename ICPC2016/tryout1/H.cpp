#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    vector<long long> st, A, lazy;
    int n;
    int left(int p) {return p << 1;};
    int right(int p) {return (p << 1) + 1;};

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            long long p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1 + p2;
        }
    }

    long long rmq(int p, int L, int R, int i, int j) {
        if (lazy[p]) {
            if (L != R) {
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }
            st[p] += lazy[p] * (R - L + 1);
            lazy[p] = 0;
        }

        if (i > R || j < L) return -1;

        if (L >= i && R <= j) return st[p];

        long long p1 = rmq(left(p), L, (L + R) / 2, i , j);
        long long p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return p1 + p2;
    }

    long long update_range(int p, int L, int R, int i, int j, long long value) {
        if (lazy[p]) {
            if (L != R) {
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }
            st[p] += lazy[p] * (R - L + 1);
            lazy[p] = 0;
        }

        if (i > R || j < L)
            return st[p];

        if (L >= i && R <= j) {
            st[p] += value * (R - L + 1);
            if (L != R) {
                lazy[left(p)] += value;
                lazy[right(p)] += value;
            }
            return st[p];
        }

        long long p1 = update_range(left(p), L, (L + R) / 2, i, j, value);
        long long p2 = update_range(right(p), (L + R) / 2 + 1, R, i, j, value);

        return st[p] = p1 + p2;
    }
public:
    SegmentTree(const vector<long long> &_A) {
        A = _A; n = A.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    long long rmq(int i, int j) {return rmq(1, 0, n - 1, i ,j);}
    void update_range(int i, int j, long long value) {update_range(1, 0, n - 1, i, j, value);}
};

int main() {
    int n;
    cin >> n;

    SegmentTree larger(vector<long long>(100100, 0)), pairs(vector<long long>(100100, 0));

    long long answer = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        answer += pairs.rmq(num, num);
        larger.update_range(0, num - 1, 1);
        pairs.update_range(0, num - 1, larger.rmq(num, num));
    }
    cout << answer << "\n";
}
