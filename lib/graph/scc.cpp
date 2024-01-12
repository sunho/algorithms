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

struct two_sat {
  int n;
  vector<int> res;
  SCC scc;
 
  two_sat(int n) : n(n), scc(2*n) {}
 
  int inv(int v) {
    if (v < n)
      return n + v;
    else
      return v - n;
  }
 
  int norm(int v){
    if (v >= n)
      return v - n;
    return v;
  }
 
  // a or b <=> (~b => a and ~a => b)
  void either(int a, int b) {
    scc.add(inv(a), b);
    scc.add(inv(b), a);
  }
 
  bool run() {
    scc.run();
  
    res.assign(n, -1);
    for (int i=scc.cnt-1;i>=0;i--){
      for (int a : scc.in[i]) {
        if (scc.col[a] == scc.col[inv(a)]) {
          return false;
        }
        if (res[norm(a)] == -1)
          res[norm(a)] = a < n;
      }
    }
    return true;
  }
};
