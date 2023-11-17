#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<vector<int>> adj(n);
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> sz(n);
  auto dfs = [&](auto&& self, int u, int p) -> int {
    sz[u] = 1;
    for (int v : adj[u]) {
      if (v == p) continue;
      sz[u] += self(self, v, u);
    }
    return sz[u];
  };
  dfs(dfs, 0, -1);
  auto dfs2 = [&](auto&& self, int u, int p) -> ll {
    ll sum = 0;
    if (p != -1) {
      sum += (ll)(A[p] ^ A[u]) * sz[u];
    }
    for (int v : adj[u]) {
      if (v == p) continue;
      sum += self(self, v, u);
    }
    return sum;
  };
  ll root = dfs2(dfs2, 0, -1);
  vector<ll> ans(n);
  auto dfs3 = [&](auto&& self, int u, int p, ll val) -> void {
    for (int v : adj[u]) {
      if (v == p) continue;
      ans[v] = val - (ll)(A[u]^A[v])*sz[v] + (ll)(A[u]^A[v])*(n-sz[v]);
      self(self, v, u, ans[v]);
    }
  };
  dfs3(dfs3, 0, -1, root);
  ans[0] = root;
  for (int i=0;i<n;i++){
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
