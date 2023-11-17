#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, t;
  cin >> n >> t;
  vector<vector<pair<int,int>>> adj(n);
  for (int i=0;i<t;i++) {
    int m;
    cin >> m;
    for (int j=0;j<m;j++){
      int u, v;
      cin >> u >> v;
      --u,--v;
      adj[u].push_back({v,i});
      adj[v].push_back({u,i});
    }
  }
  int k;
  cin >> k;
  vector<vector<int>> T(t);
  for (int i=0;i<k;i++){
    int z;
    cin >> z;
    --z;
    T[z].push_back(i);
  }
  const int inf = 1e9;
  vector<int> dist(n, inf);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  dist[0] = 0;
  pq.push({0,0});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dist[u] != d) continue;
    for (auto [v, tt] : adj[u]) {
      int ti = lower_bound(begin(T[tt]), end(T[tt]), d) - begin(T[tt]);
      if (ti == T[tt].size()) continue;
      int nd = T[tt][ti]+1;
      if (dist[v] > nd) {
        dist[v] = nd;
        pq.push({nd, v});
      }
    }
  }
  if (dist[n-1] == inf) dist[n-1] = -1;
  cout << dist[n-1] << "\n";
}
