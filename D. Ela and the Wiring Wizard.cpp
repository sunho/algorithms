#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  const int inf = 1e9;
  vector<vector<int>> dist(n, vector<int>(n,inf));
  for (int i=0;i<n;i++){
    dist[i][i] = 0;
  }
  vector<tuple<int,int,int>> edges;
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    dist[u][v] = 1;
    dist[v][u] = 1;
    edges.push_back({u,v,w});
  }
  for (int k=0;k<n;k++){
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  ll infl = 1e18;
  ll ans = infl;
  for (int i=0;i<m;i++){
    auto [u,v,w] = edges[i];
    ans = min(ans,(ll)(dist[0][u] + dist[v][n-1] + 1)*w);
    ans = min(ans,(ll)(dist[0][v] + dist[u][n-1] + 1)*w);
    for (int x=0;x<n;x++){
      ans = min(ans,(ll)(dist[0][x] + dist[x][n-1] + dist[u][x] + 2)*w);
      ans = min(ans,(ll)(dist[0][x] + dist[x][n-1] + dist[v][x] + 2)*w);
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
