#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector dist(n, 0);
  vector dp(n, 0);
  auto dfs = [&](int u, int p, auto&& self) -> void {
    int maxi_dis = 0;
    int next_maxi_dis = 0;
    int max_dp = 0;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(v, u, self);
      if (maxi_dis <= dist[v] + 1) {
        next_maxi_dis = maxi_dis;
        maxi_dis = dist[v] + 1;
      } else if (next_maxi_dis <= dist[v] + 1) {
        next_maxi_dis = dist[v] + 1;
      }
      max_dp = max(max_dp, dp[v]);
    }
    dist[u] = maxi_dis;
    dp[u] = max(maxi_dis + next_maxi_dis, max_dp); 
  };
  dfs(0, -1, dfs);
  cout << dp[0] << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
