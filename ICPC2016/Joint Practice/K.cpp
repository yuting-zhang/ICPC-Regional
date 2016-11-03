#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long lcm(long long a, long long b) {
  long long gcd = __gcd(a, b);
  return a / gcd * b;
}

int main()
{
  long long N, K;
  vector<long long> v;
  scanf("%lld%lld", &N, &K);
  for (int i=0;i<K;i++) {
    long long t;
    scanf("%lld", &t);
    v.push_back(t);
  }
  long long ans = 0;
  for (int i=0;i<(1<<K);i++) {
    long long l = 1;
    int cur = 0;
    for (int j=0;j<K;j++) {
      if ((1<<j) & i) {
        cur++;
        l = lcm(l, v[j]);
      }
    }
    if (cur % 2 == 0) {
      ans += N / l;
    } else {
      ans -= N / l;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
