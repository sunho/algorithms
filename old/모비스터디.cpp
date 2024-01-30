#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;

void solve() {
  int n,m,s,t;
  cin >> n >> m >> s >> t;
  --s,--t;
  vector<vector<pair<int,int>>> adj(n);
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  vector<vector<ll>> dist(2, vector<ll>(n,-1));
  pqg<pair<ll,int>> pq;
  for (int z=0;z<2;z++) {
    if (z == 0) pq.push({0,s});
    else pq.push({0,t});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (dist[z][u] != -1) continue;
      dist[z][u] = d;
      for (auto [v,w] : adj[u]) {
        ll nd = d+w;
        if (dist[z][v] == -1)  {
          pq.push({nd,v});
        }
      }
    }
  }
  vector<int> ans;
  ll dd = dist[0][t];
  for (int i=0;i<n;i++){
    if (dist[0][i] + dist[1][i] == dd) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << "\n";
  for (int v : ans) {
    cout << v+1 << " ";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
