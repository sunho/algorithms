#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector adj(n, vector<int>());
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector dp(n, array<int,2>{});
  auto dfs = [&](auto self, int u, int p) -> void {
    int sum = 0;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      sum += dp[v][0];
    }
    for (int v : adj[u]) {
      if (v == p) continue;
      dp[u][0] = max(dp[u][0], sum + 1 - dp[v][0] + dp[v][1]);
    }
    dp[u][1] = sum;
  };
  dfs(dfs, 0, -1);
  cout << max(dp[0][0], dp[0][1]);
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
