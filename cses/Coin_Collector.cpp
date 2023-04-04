#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SCC {
  int n;
  vector<vector<int>> adj, adj_inv;
  vector<vector<int>> comps;
  vector<int> comp_ids;
  int num_comp = 0;
  SCC(int n) : n(n), adj(n), adj_inv(n) {}

  void add(int u, int v) {
    adj[u].push_back(v);
    adj_inv[v].push_back(u);
  }

  void run() {
    vector<bool> vis(n);
    vector<int> order;
    for (int i=0;i<n;i++)
      if(!vis[i])
        topo_dfs(vis, order, i);
    
    comp_ids.assign(n, 0);
    vis.assign(n, false);
    reverse(begin(order), end(order));
    for (int i : order)
      if (!vis[i]) {
        comps.push_back({});
        comp_dfs(vis, i);
        num_comp++;
      }
  }

  void topo_dfs(vector<bool>& vis, vector<int>& order, int u) {
    vis[u] = true;
    for (int v : adj[u]) {
      if (!vis[v])
        topo_dfs(vis, order, v);
    }
    order.push_back(u);
  }

  void comp_dfs(vector<bool>& vis, int u) {
    vis[u] = true;
    comp_ids[u] = num_comp;
    comps.back().push_back(u);
    for (int v : adj_inv[u]) {
      if (!vis[v])
        comp_dfs(vis, v);
    }
  }
};

int main() {
  int n,m;
  cin >> n >> m;
  SCC scc(n);
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }

  while(m--){
    int u,v;
    cin >> u >> v;
    --u,--v;
    scc.add(u,v);
  }
  scc.run();

  vector<ll> dp(scc.num_comp, -1);
  auto dfs = [&](auto self, int c) -> void {
    ll res = 0;
    set<int> adj_comps;
    for (int u : scc.comps[c]) {
      res += A[u];
      for (int v : scc.adj[u]) {
        int nc = scc.comp_ids[v];
        if (c != nc) adj_comps.insert(nc);
      }
    }
    ll dp_max = 0;
    for (int nc : adj_comps) {
      if (dp[nc] == -1) {
        self(self, nc);
      }
      dp_max = max(dp_max, dp[nc]);
    }
    res += dp_max;
    dp[c] = res;
  };

  ll ans = 0;
  for (int i=0;i<scc.num_comp;i++){
    if (dp[i] == -1) {
      dfs(dfs, i);
      ans = max(ans, dp[i]); 
    }
  }

  cout << ans << "\n";
}
