#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i=0;i<n-1;i++) {
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> dp(n);
  auto dfs = [&](auto& self, int u, int p) -> void {
    bool visited = false;
    for (int v : adj[u]) {
      if (p == v) continue;
      visited = true;
      self(self, v, u);
      dp[u] += dp[v];
    }
    if (!visited) {
      dp[u] = 1;
    }
  };
  dfs(dfs,0,-1);
  int q;
  cin >> q;
  while (q--) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    cout << (ll)dp[u]*dp[v] << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve(); 
  }
}
