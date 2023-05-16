#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct bipariate_match {
  int n,m;
  vector<int> mt;
  vector<vector<int>> adj;
  bipariate_match(int n, int m) : n(n), m(m), mt(m, -1), adj(n, vector<int>()) {}
  void add(int u, int v) {
    adj[u].push_back(v);
  }
  void run() {
    vector<bool> vis;
    auto dfs = [&](auto self, int u) -> bool {
      if (vis[u]) return false;
      vis[u] = true;
      for (int v : adj[u]) {
        if (mt[v] == -1 || self(self, mt[v])) {
          mt[v] = u;
          return true;
        }
      }
      return false;
    };
    vector<bool> used(n);
    for (int i=0;i<n;i++){
      for (int v : adj[i]) {
        if (mt[v] == -1) {
          mt[v] = i;
          used[i] = true;
          break;
        }
      }
    }

    for (int i=0;i<n;i++) {
      if (used[i]) continue;
      vis.assign(n, false);
      dfs(dfs, i);
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  int k;
  cin >> k;
  bipariate_match match(n,m);
  for (int i=0;i<k;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    match.add(u,v);
  }
  match.run();
  vector<pair<int,int>> ans;
  for (int i=0;i<m;i++){
    if (match.mt[i] != -1) {
      ans.push_back({match.mt[i], i});
    }
  }
  cout << ans.size() << "\n";
  for (auto [u,v] : ans) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
}
