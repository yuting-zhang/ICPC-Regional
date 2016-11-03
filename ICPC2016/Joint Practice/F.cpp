#include <vector>
#include <iostream>
#include <cstring>
using namespace std;


const int maxn = 160;
vector<int> g[maxn];
bool is_in[maxn][maxn];

vector<int> get_first() {
  // cout << "kao";
  vector<int> ans;
  bool is[maxn];
  memset(is, 0, sizeof(is));
  ans.push_back(1);
  is[1] = true;
  while(1) {
    int last = ans[ans.size()-1];
    bool should = false;
    for (int i=0;i<g[last].size();i++) {
      int cur = g[last][i];
      if (!is[cur]) {
        ans.push_back(cur);
        is[cur] = true;
        should = true;
        break;
      }
    }
    if (!should) {
      break;
    }
  }
  // cout << ans.size() << endl;
  int index = 0;
  int last = ans[ans.size()-1];
  for (index = 0;;index++) {
    if (is_in[ans[index]][last])
      break;
  }
//  cout << index;
  vector<int> f;
  for (int i=index;i<ans.size();i++)
    f.push_back(ans[index]);
  return f;
}

int main()
{
  int n, m;
  while (cin >> n >> m) {

    memset(is_in, 0, sizeof(is_in));
    //cout << m;
    int c, d;
    for (int i=0;i<m;i++) {
      cin >> c >> d;
      // cout << "kao";
      //cout << c << d;
      g[c].push_back(d);
      g[d].push_back(c);
      //cout << "lk";
      is_in[c][d] = is_in[d][c] = true;
    }
    //cout << "kao";
    vector<int> fir = get_first();
    while (fir.size() < n) {
      
    }
    // cout << fir.size() << endl;
    // for (int i=0;i<fir.size();i++) {
    //   cout <<  fir[i] << endl;
    // }
    for (int i=1;i<=n;i++)
      g[i].clear();
  }
  return 0;
}
