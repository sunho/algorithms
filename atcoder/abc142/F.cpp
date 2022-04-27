#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    g[a].push_back(b);
  }
  deque<int> ans;
  const int inf = 1e9;
  int ans_len = inf;
  auto bfs = [&](int s) {
    vector<int> d(n,-1);
    vector<int> p(n,-1);
    queue<int> q;
    int e = -1;
    q.push(s);
    d[s] = 0;
    while (!q.empty()){
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (v == s && e == -1) {
          e = u;
          continue;
        }
        if (d[v] == -1) {
          d[v] = d[u] + 1;
          p[v] = u;
          q.push(v);
        }
      }
    }
    if (e != -1) {
      if (ckmin(ans_len, d[e] + 1)) {
        ans.clear();
        int v = e;
        while(v!=s) {
          ans.push_front(v);
          v = p[v];
        }
        ans.push_front(s);
      }
    }
  };
  for(int i=0;i<n;i++){
    bfs(i);
  }
  if (ans_len == inf) {
    cout << -1 << "\n";
  } else {
    cout << ans.size() << "\n";
    for(auto v : ans) {
      cout << v+1 << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
