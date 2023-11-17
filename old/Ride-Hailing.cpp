#include <bits/stdc++.h>

using namespace std;

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

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  const int inf = 1e9;
  vector<vector<int>> dist(n, vector<int>(n, inf));
  for (int i=0;i<n;i++){
    dist[i][i] = 0;
  }
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    dist[u][v] = min(dist[u][v],w);
  }
  for (int k=0;k<n;k++){
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  vector<tuple<int,int,int>> A(k);
  for (int i=0;i<k;i++) {
    int x,y,t;
    cin >> x >> y >> t;
    --x,--y;
    A[i] = {t,x,y};
  }

  bipariate_match match(k, k);
  for (int i=0;i<k;i++){
    for (int j=0;j<k;j++){
      if (i == j) continue;
      auto [t0,x0,y0] = A[i];
      auto [t1,x1,y1] = A[j];
      if (t0 + dist[x0][y0] + dist[y0][x1] > t1) {
        continue;
      }
      match.add(j, i);
    }
  }
  match.run();
  vector<int> id(k);
  iota(begin(id),end(id),0);
  sort(begin(id),end(id),[&](int i, int j) {
    return A[i] < A[j];
  });
  int ans = 0;
  vector<int> vis(k);
  for (int i=0;i<k;i++){
    if (vis[id[i]]) continue;
    vis[id[i]] = true;
    ans++;
    int cur = id[i];
    while (match.mt[cur] != -1) {
      cur = match.mt[cur];
      if (cur != -1)
        vis[cur] = true;
    }
  }
  cout << ans << "\n";
}
