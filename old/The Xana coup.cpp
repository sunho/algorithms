#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  const ll inf = 1e9;
  vector<array<array<ll,2>,2>> dp(n, {{{-1,-1},{-1,-1}}});
  auto dfs = [&](auto&& self, int u, int p) -> void {
    array<ll,2> sum{};
    vector<vector<ll>> diff(2);
    for (int v : adj[u]) {
      if (v == p) continue;
      if (dp[v][0][0] == -1) self(self, v, u);
      sum[0] += dp[v][0][0];
      sum[1] += dp[v][1][0];
      diff[0].push_back(dp[v][0][1]-dp[v][0][0]);
      diff[1].push_back(dp[v][1][1]-dp[v][1][0]);
    }
    sort(begin(diff[0]),end(diff[0]));
    sort(begin(diff[1]),end(diff[1]));
    for (int i=0;i<2;i++){
      for (int j=0;j<2;j++) {
        int st = A[u] ^ j;
        int odd = i ^ st;
        ll cur = sum[j] + j;
        dp[u][i][j] = inf;
        if (!odd)
          dp[u][i][j] = cur;
        for (int z=0;z<diff[j].size();z++) {
          cur += diff[j][z];
          if ((z%2)!=odd) {
            dp[u][i][j] = min(dp[u][i][j], cur);
          }
        }
      }
    }
  };
  dfs(dfs, 0, -1);
  ll ans = min(dp[0][0][0], dp[0][0][1]);
  if (ans == inf) {
    cout << "impossible" << "\n";
  } else {
    cout << ans << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
