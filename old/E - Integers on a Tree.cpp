#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i=0;i<n-1;i++) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int k;
  cin >> k;
  vector<int> V(k), P(k);
  vector<int> marked(n,-1);
  for (int i=0;i<k;i++) {
    cin >> V[i] >> P[i];
    --V[i];
    marked[V[i]] = P[i];
  }
  const int inf = 1e9;
  vector<pair<int,int>> dp(n);
  bool ok = true;
  auto merge = [](pair<int,int>& a, pair<int,int> b, int level) {
    a.first = max(a.first, b.first);
    a.second = min(a.second, b.second);
    if (a.first > a.second || (a.first == a.second && (a.first&1) != level)) {
      return false;
    }
    return true;
  };
  auto dfs = [&](auto&& self, int u, int p, int level) -> pair<int,int> {
    pair<int,int> cand = marked[u] != -1 ? make_pair(marked[u],marked[u]) : make_pair(-inf,inf);
    for (int v : adj[u]) {
      if (v == p) continue;
      auto res = self(self, v, u, level^1);
      res.first-=1;
      res.second+=1;
      ok &= merge(cand, res, level);
    }
    return dp[u] = cand;
  };
  auto dfs2 = [&](auto&& self, int u, int p, int level) -> void {
    if (p != -1) {
      auto res = dp[p];
      res.first -= 1;
      res.second += 1;
      ok &= merge(dp[u], res, level);
    }
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u, level^1);
    }
  };
  dfs(dfs, 0, -1, 0);
  dfs2(dfs2, 0, -1, 0);
  if (!ok) {
    ok = true;
    dfs(dfs, 0, -1, 1);
    dfs2(dfs2, 0, -1, 1);
  }
  if (!ok) {
    cout << "No" << "\n";
    return 0;
  }
  cout << "Yes" << "\n";
  for (int i=0;i<n;i++) {
    cout << dp[i].first << "\n";
  }
}
