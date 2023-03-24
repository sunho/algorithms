#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> prd(n), tin(n), tout(n);
  int timer = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    prd[u] = p;
    tin[u] = timer++;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v,u);
    }
    tout[u] = timer-1;
  };
  dfs(dfs, 0, 0);

  int l = ceil(log2(n));
  vector<array<int,32>> up(n);
  for (int i=0;i<l;i++){
    for (int j=0;j<n;j++){
      if (i == 0)
        up[j][i] = prd[j];
      else
        up[j][i] = up[up[j][i-1]][i-1];
    }
  }

  auto is_ancestor = [&](int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
  };

  vector<int> vals(n);
  while (m--){
    int u,v;
    cin >> u >> v;
    --u,--v;

    if (is_ancestor(u, v)) {
      if (u != 0)
        vals[tin[prd[u]]]--;
      vals[tin[v]]++;
    } else if (is_ancestor(v, u)) {
      if (v != 0)
        vals[tin[prd[v]]]--;
      vals[tin[u]]++;
    } else {
      vals[tin[u]]++;
      vals[tin[v]]++;
      for (int i=l-1;i>=0;i--){
        if (!is_ancestor(up[u][i], v))
          u = up[u][i];
      }
      u = up[u][0];
      vals[tin[u]]--;
      if (u != 0)
        vals[tin[prd[u]]]--;
      }
  }
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i]+vals[i];
  }
  for (int i=0;i<n;i++){
    cout << pf[tout[i]+1] - pf[tin[i]] << " ";
  }
}
