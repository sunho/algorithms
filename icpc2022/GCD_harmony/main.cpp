#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sieves(int PN, vector<vector<int>>& pr) {
  pr.assign(PN+1,{});
  for (int i=2;i<=PN;i++) {
    if (pr[i].empty()) {
      for (int j=i;j<=PN;j+=i) {
        pr[j].push_back(i);
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector adj(n, vector<int>());
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  const int N = max(2*n,100);
  vector<int> cnt(n);
  const ll inf = 1e9;
  vector<vector<int>> W(N+1);
  sieves(N, W);
  vector<vector<ll>> dp(n, vector(N+1, 0ll));

  auto dfs = [&](auto self, int u, int p) -> void {
    cnt[u] = 1;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      cnt[u] += cnt[v];
    }
    for (int i=2;i<=N;i++){
      if (i == A[u]) continue;
      dp[u][i] = i;
    }
    for (int d=2;d<=N;d++){
      for (int v : adj[u]) {
        if (v == p) continue;
        ll mn = inf;
        for (int pi : W[d]) {
          mn = min(mn,dp[v][pi]);
        }
        dp[u][d] += mn;
      }
    }
    for (int d=2;d<=N;d++){
     for (int pi : W[d]) {
        dp[u][pi] = min(dp[u][pi], dp[u][d]);
      }
    }
  };
  dfs(dfs, 0, -1);
  ll ans = inf;
  for (int d=2;d<=N;d++){
    ans = min(ans, dp[0][d]);
  }
  cout << ans << "\n";
}
