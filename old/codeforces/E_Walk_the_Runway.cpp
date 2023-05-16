#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  vector<int> A(m);
  for (int i=0;i<m;i++) cin >> A[i];
  vector<vector<int>> R(n, vector<int>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> R[i][j];
    }
  }

  const int N = 5000;

  vector<bitset<N>> adj(m);
  for (int i=0;i<m;i++){
    adj[i].set();
  }

  for (int i=0;i<n;i++){
    bitset<N> pre;
    pre.set();
    vector<int> id(m);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int x, int y) {
      return R[i][x] < R[i][y];
    });
    for (int l=0,j=0;j<m;j++){
      while (l < m && R[i][id[l]] == R[i][id[j]]) {
        pre[id[l]] = false;
        l++;
      }
      adj[id[j]] &= pre;
    }
  }

  vector<bool> vis(m);
  vector<int> order;
  auto dfs = [&](auto self, int u) -> void {
    vis[u] = true;
    for (int v=0;v<m;v++){
      if (adj[u][v] && !vis[v]) {
        self(self, v);
      }
    }
    order.push_back(u);
  };
  for (int i=0;i<m;i++){
    if (!vis[i]) dfs(dfs, i);
  }
  vector<ll> dp(m);
  for (int u : order) {
    dp[u] = A[u];
    for (int v=0;v<m;v++){
      if (adj[u][v]) {
        dp[u] = max(dp[u], dp[v] + A[u]);
      }
    }
  }
  ll ans = 0;
  for (ll x : dp) {
    ans = max(ans, x);
  }
  cout << ans << "\n";
}
