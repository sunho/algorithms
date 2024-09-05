#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> C(n);
  string s;
  cin >> s;
  for (int i=0;i<n;i++){
    if (s[i] == 'W') {
      C[i] = 1;
    }
  }
  vector<int> dp(n);
  vector<int> ans(n);
  bool ok = true;
  auto dfs = [&](auto&& self, int u, int p) -> pair<char,char> {
    int cnt = 0;
    int col = -1;
    array<int, 2> cnt2{};
    for (int v : adj[u]) {
      if (p == v) continue;
      cnt ++;
      auto [free, force] = self(self, v, u);
      if (force)  {
        if (col == -1) {
          col = C[v];
        } else {
          if (col != C[v]) {
            ok = false;
          }
        }
      }
      if (free) {
        ans[v] = C[u];
      }
      cnt2[ans[v]]++;
    }
    if (cnt == 0) {
      return {1, 1};
    }
    pair<char,char> ret{false,true};
    ret.second = cnt2[0] == cnt2[1];
    if (cnt2[C[u]] < cnt2[C[u]^1]) {
      ok = false;
    }
    if (col == -1) {
      ret.first = true;
    } else {
      ans[u] = col;
    }
    return ret;
  };
  dfs(dfs,0,-1);
  if (!ok) {
    cout << -1 << "\n";
    return;
  }
  for (int i=0;i<n;i++){
    if (ans[i]) cout << 'W';
    else cout << 'B';
  }
  cout << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
