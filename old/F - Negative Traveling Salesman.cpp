#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  const ll inf = 1e18;
  vector<vector<ll>> dist(n, vector<ll>(n, inf));
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    dist[u][v] = min(dist[u][v], (ll)w);
  }
  for (int k=0;k<n;k++){
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  const int N = 1 << n;
  vector<vector<ll>> dp(n, vector<ll>(N, inf));
  for (int i=0;i<n;i++){
    dp[i][1<<i] = 0;
  }
  for (int msk=1;msk<N;msk++){
    for (int i=0;i<n;i++){
      if (!(msk >> i & 1)) continue;
      for (int j=0;j<n;j++) {
        if (i == j) continue;
        if (!(msk >> j & 1)) {
          continue;
        }
        if (dist[j][i] != inf && dp[j][msk ^ (1<<i)] != inf)
          dp[i][msk] = min(dp[i][msk], dp[j][msk ^ (1<<i)] + dist[j][i]);
      }
    }
  }
  ll ans = inf;
  for (int i=0;i<n;i++){
    ans = min(ans, dp[i][N-1]);
  }
  if (ans == inf) {
    cout << "No";
    return;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
