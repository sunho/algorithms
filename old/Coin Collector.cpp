#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct SCC {
  int n;
  int cnt;
  vector<vector<int>> adj, adj_inv;
  vector<int> col;
  vector<vector<int>> in;
  SCC(int n) : n(n), cnt(0), adj(n), adj_inv(n), col(n,-1) {}
  void add(int u, int v) {
    adj[u].push_back(v);
    adj_inv[v].push_back(u);
  }

  void run() {
    stack<int> st;
    vector<int> vis(n);
    auto dfs = [&](auto&& self, int u) -> void {
      vis[u] = true;
      for (int v : adj[u]) if (!vis[v]) self(self, v);
      st.push(u);
    };
    for (int i=0;i<n;i++)
      if (!vis[i]) dfs(dfs, i);
    auto dfs2 = [&](auto&& self, int u, int c) -> void {
      col[u] = c;
      if (c >= in.size()) in.push_back({});
      in[c].push_back(u);
      for (int v : adj_inv[u]) if (col[v] == -1) self(self, v, c);
    };
    while (!st.empty()) {
      int u = st.top(); st.pop();
      if (col[u] != -1) continue;
      dfs2(dfs2, u, cnt++);
    }
  }

  void build_adj(vector<vector<int>> &res, vector<vector<int>> &res_inv) {
    res.assign(cnt, {});
    res_inv.assign(cnt, {});
    for (int u = 0; u < n; u++) {
      for (int v : adj[u]) {
        int c = col[u];
        int nc = col[v];
        if (c != nc) {
          res[c].push_back(nc);
          res_inv[nc].push_back(c);
        }
      }
    }
    for (int c = 0; c < cnt; c++) {
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
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  while (m--) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    scc.add(u,v);
  }
  scc.run();

  vector<ll> dp(scc.cnt, 0);
  for (int c=scc.cnt-1;c>=0;c--){
    ll dp_max = 0;
    for (int u : scc.in[c]) {
      dp[c] += A[u];
      for (int v : scc.adj[u]) {
        v = scc.col[v];
        if (v == c) continue;
        dp_max = max(dp_max, dp[v]);
      }
    }
    dp[c] += dp_max;
  }
  cout << *max_element(begin(dp),end(dp)) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
