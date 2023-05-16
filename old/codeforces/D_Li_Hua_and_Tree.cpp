#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];

  vector adj(n, set<int>());
  vector prd(n,-1);
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  vector<set<pair<int,int>>> sz(n);
  vector<int> dp_sz(n);
  vector<ll> dp_sum(n);
  auto dfs = [&](auto self, int u, int p) -> void {
    dp_sz[u] = 1;
    dp_sum[u] = A[u];
    prd[u] = p;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      dp_sz[u] += dp_sz[v];
      dp_sum[u] += dp_sum[v];
      sz[u].insert({-dp_sz[v], v});
    }
  };
  dfs(dfs, 0, -1);

  while (m--) {
    int t;
    cin >> t;
    if (t == 2) {
      int x;
      cin >> x;
      --x;
      if (sz[x].empty())
        continue;
      auto [_, k] = *sz[x].begin();
      sz[x].erase({_,k});
      if (prd[x] != -1) {
        sz[prd[x]].erase({-dp_sz[x], x});
        sz[prd[x]].insert({-dp_sz[x], k});
      }
      ll tmp = dp_sum[x];
      dp_sum[x] -= dp_sum[k];
      dp_sum[k] = tmp;
      int tmp2 = dp_sz[x];
      dp_sz[x] -= dp_sz[k];
      dp_sz[k] = tmp2;
      prd[k] = prd[x];
      prd[x] = k;
      sz[k].insert({-dp_sz[x], x});
    } else {
      int x;
      cin >> x;
      --x;
      cout << dp_sum[x] << "\n";
    }
  }
}
