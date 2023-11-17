#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i=1;i<n;i++){
    int u;
    cin >> u;
    --u;
    adj[u].push_back(i);
    adj[i].push_back(u);
  }
  vector<int> cnt(n);
  auto dfs = [&](auto&& self, int u, int p) -> void {
    cnt[u] = 1;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      cnt[u] += cnt[v];
    }
  };
  dfs(dfs,0,-1);
  ll ans = 0;
  auto dfs2 = [&](auto&& self, int u, int p) -> void {
    int tot = cnt[u]-1;
    vector<bool> dp(tot+1);
    dp[0] = true;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      for (int i=tot;i>=1;i--){
        if (i - cnt[v] >= 0 && dp[i-cnt[v]]) {
          dp[i] = true;
        }
      }
    }
    ll res = 0;
    for (int i=0;i<=tot;i++){
      if (dp[i])
        res = max(res, (ll)i*(tot-i));
    }
    ans += res;
  };
  dfs2(dfs2, 0, -1);
  cout << ans << "\n";
}
