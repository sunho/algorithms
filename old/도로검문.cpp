#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int,int,int>> edges;
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    edges.push_back({u,v,w});
  }
  vector<vector<int>> inv(m, vector<int>(n));
  vector<vector<pair<int,int>>> adj(n);
  for (int i=0;i<m;i++){
    auto [u,v,w] = edges[i];
    inv[i][u] = adj[u].size();
    inv[i][v] = adj[v].size();
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  const int inf = 1e9;
  auto go = [&](int ban) {
    if (ban != -1) {
      auto [u,v,w] = edges[ban];
      adj[u][inv[ban][u]].second = inf;
      adj[v][inv[ban][v]].second = inf;
    }
    pqg<pair<int,int>> pq;
    pq.push({0,0});
    vector<int> dist(n,inf);
    dist[0] = 0;
    while (!pq.empty()) {
      auto [d,u] = pq.top();
      pq.pop();
      if (dist[u] != d) continue;
      for (auto [v,w] : adj[u]) {
        int nd = d+w;
        if (dist[v] > nd) {
          dist[v] = nd;
          pq.push({nd,v});
        }
      }
    }
    if (ban != -1) {
      auto [u,v,w] = edges[ban];
      adj[u][inv[ban][u]].second = w;
      adj[v][inv[ban][v]].second = w;
    }
    return dist;
  };
  auto dist = go(-1);
  int ans = -inf;
  for (int i=0;i<m;i++){
    auto [u,v,w] = edges[i];
    // belongs to dijsktra tree
    if (dist[u] + w == dist[v] || dist[v] + w == dist[u]) {
      int cand = go(i)[n-1];
      if (cand != inf) {
        ans = max(ans, cand-dist[n-1]);
      } else {
        cout << -1 << "\n";
        return;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
