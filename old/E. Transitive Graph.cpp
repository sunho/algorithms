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

  // add edge
  void add(int u, int v) {
    adj[u].push_back(v);
    adj_inv[v].push_back(u);
  }

  // find strongly connected components of graph
  void run() {
    vector<bool> vis(n);
    vector<int> order;
    auto topo_dfs = [&](auto self, int u) -> void {
      vis[u] = true;
      for (int v : adj[u])
        if (!vis[v])
          self(self, v);
      order.push_back(u);
    };
    for (int i = 0; i < n; i++)
      if (!vis[i])
        topo_dfs(topo_dfs, i);
    reverse(begin(order), end(order));
    comp_ids.assign(n, 0);
    vis.assign(n, false);
    auto comp_dfs = [&](auto self, int u) -> void {
      vis[u] = true;
      comp_ids[u] = num_comp;
      comps.back().push_back(u);
      for (int v : adj_inv[u])
        if (!vis[v])
          self(self, v);
    };
    for (int i : order)
      if (!vis[i]) {
        comps.push_back({});
        comp_dfs(comp_dfs, i);
        num_comp++;
      }
  }

  void build_adj(vector<vector<int>> &res, vector<vector<int>> &res_inv) {
    res.assign(num_comp, {});
    res_inv.assign(num_comp, {});
    for (int u = 0; u < n; u++) {
      for (int v : adj[u]) {
        int c = comp_ids[u];
        int nc = comp_ids[v];
        if (c != nc) {
          res[c].push_back(nc);
          res_inv[nc].push_back(c);
        }
      }
    }
    for (int c = 0; c < num_comp; c++) {
      sort(begin(res[c]), end(res[c]));
      sort(begin(res_inv[c]), end(res_inv[c]));
      res[c].resize(unique(begin(res[c]), end(res[c])) - begin(res[c]));
      res_inv[c].resize(unique(begin(res_inv[c]), end(res_inv[c])) -
                        begin(res_inv[c]));
    }
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  SCC scc(n);
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    scc.add(u, v);
  }
  scc.run();
  vector<vector<int>> adj2, adj2_inv;
  scc.build_adj(adj2, adj2_inv);

  vector<pair<int, ll>> dp(scc.num_comp, {0, -1});
  const ll inf = 1e18;
  auto dfs = [&](auto self, int c) -> void {
    ll res = 0;
    int cnt = 0;
    set<int> adj_comps;
    for (int u : scc.comps[c]) {
      res += A[u];
      cnt += 1;
    }
    pair<int, ll> mx = make_pair(-cnt, res);
    for (int nc : adj2[c]) {
      if (dp[nc].first == 0) {
        self(self, nc);
      }
      auto [cnt2, mx2] = dp[nc];
      mx = min(mx, {cnt2 - cnt, (ll)res + mx2});
    }
    dp[c] = mx;
  };

  pair<int, ll> ans = {0, inf};
  for (int i = 0; i < scc.num_comp; i++) {
    if (dp[i].first == 0 && adj2_inv[i].size() == 0) {
      dfs(dfs, i);
      ans = min(ans, dp[i]);
    }
  }

  cout << -ans.first << " " << ans.second << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
