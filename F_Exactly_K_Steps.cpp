#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;

  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> tin(n), tout(n), prd(n), dist(n);
  int timer = 0;
  auto dfs = [&](auto self, int u, int p, int level) -> void {
    tin[u] = timer++;
    dist[u] = level;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self,v,u,level+1);
      prd[v] = u;
    }
    tout[u] = timer-1;
  };
  dfs(dfs, 0, -1, 0);
  int end1 = max_element(dist.begin(), dist.end()) - dist.begin();
  dfs(dfs, end1, -1, 0);
  int end2 = max_element(dist.begin(), dist.end()) - dist.begin();
  timer = 0;
  dfs(dfs, 0, -1, 0);
  prd[0] = 0;
  vector<array<int, 32>> up(n);
  const int l = ceil(log2(n));
  for (int k=0;k<l;k++){
    for (int i=0;i<n;i++){
      if (k == 0)
        up[i][k] = prd[i];
      else
        up[i][k] = up[up[i][k-1]][k-1];
    }
  }

  auto lift = [&](int u, int k) {
    for (int i=0;i<l;i++){
      if (k & (1<<i)) {
        u = up[u][i];
      }
    }
    return u;
  };

  auto is_ancestor = [&](int p, int u) {
    return tin[p] <= tin[u] && tout[u] <= tout[p];
  };

  auto get_lca = [&](int u, int v) {
    if (is_ancestor(u,v)) {
      return u;
    }
    for (int i=l-1;i>=0;i--){
      if (!is_ancestor(up[u][i], v))
        u = up[u][i];
    }
    return up[u][0];
  };

  auto get_dist = [&](int u, int v) {
    int lca = get_lca(u,v);
    return dist[u] + dist[v] - 2*dist[lca];
  };

  int q;
  cin >> q;
  while (q--){
    int s, k;
    cin >> s >> k;
    --s;

    int cand = get_dist(s, end1) > get_dist(s, end2) ? end1 : end2;
    if (get_dist(s, cand) < k) {
      cout << -1 << "\n";
      continue;
    }
    if (is_ancestor(s, cand)) {
      cout << lift(cand, get_dist(s,cand) - k) + 1 << "\n";
    } else {
      int lca = get_lca(s,cand);
      int dist1 = get_dist(lca, s);
      int dist2 = get_dist(lca,cand);
      if (k <= dist1) {
        cout << lift(s, k) + 1 << "\n";
      } else {
        cout << lift(cand, dist2-(k-dist1)) + 1 << "\n";
      }
    }
  }
}
