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

    // arbitrary matching heuristics
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
      if (used[i]) continue; // add mt[i] != -1 check when abitrary
      vis.assign(n, false);
      dfs(dfs, i);
    }
  }
};