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
};

void solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  SCC scc(n);
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    scc.add(u,v);
    if (w == 2) {
      scc.add(v,u);
    }
  }
  scc.run();
  vector<int> vis(scc.cnt);
  for (int i=0;i<n;i++) {
    if (A[i].first == 0) {
      vis[scc.col[i]] = true;
    }
  }
  for (int i=0;i<scc.cnt;i++) {
    for (int u : scc.in[i]) {
      for (int v : scc.adj[u]) {
        v = scc.col[v];
        vis[v] |= vis[i];
      }
    }
  }

  vector<pair<int,int>> X;
  vector<pair<int,int>> Y;
  for (int i=0;i<n;i++) {
    if (A[i].first == a && vis[scc.col[i]]) {
      Y.push_back({A[i].second, i});
    }
    if (A[i].first == 0) {
      X.push_back({A[i].second,i});
    }
  }
  sort(rbegin(X), rend(X));
  sort(begin(Y),end(Y));
  
  vector<int> mx(scc.cnt, 0);
  vector<int> mn(scc.cnt, n);
  for (int i=0;i<Y.size();i++){
    int c = scc.col[Y[i].second];
    mx[c] = max(mx[c], i+1);
    mn[c] = min(mn[c], i+1);
  }

  for (int c=scc.cnt-1;c>=0;c--) {
    for (int u : scc.in[c]) {
      for (int v : scc.adj[u]) {
        v = scc.col[v];
        mx[c] = max(mx[c], mx[v]);
        mn[c] = min(mn[c], mn[v]);
      }
    }
  }

  for (int i=0;i<X.size();i++) {
    int u = X[i].second;
    if (mx[scc.col[u]] == 0) {
      cout << 0 << "\n";
    } else {
      cout << mx[scc.col[u]] - mn[scc.col[u]] + 1 << "\n";
    }
  }

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
