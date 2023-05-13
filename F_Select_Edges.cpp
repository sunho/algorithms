#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;

  vector adj(n, vector<pair<int,int>>());
  vector<int> D(n);
  for (int i=0;i<n;i++){
    cin >> D[i];
  }
  for (int i=0;i<n-1;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  const ll inf = 2e18;
  vector<array<ll,2>> dp(n, {-inf,-inf});
  auto dfs = [&](auto self, int u, int p, int k) -> void {
    int rem = D[u] - k;
    vector<ll> cands;
    ll res = 0;
    for (auto [v,w] : adj[u]) {
      if (v == p) continue;
      if (dp[v][0] == -inf) self(self,v,u,0);
      if (D[v] != 0) {
        if (dp[v][1] == -inf) self(self,v,u,1);
      }
      ll cand1 = D[v] != 0 ? dp[v][1] + w : -inf;
      ll cand2 = dp[v][0];
      res += cand2;
      cands.push_back({cand1-cand2});
    }
    sort(rbegin(cands), rend(cands));
    for (int i=0;i<min(rem,(int)cands.size());i++){
        if (cands[i] < 0) break;
        res += cands[i];
    }
    dp[u][k] = res;
  };
  dfs(dfs, 0, -1, 0);
  cout << dp[0][0] << "\n";
}
