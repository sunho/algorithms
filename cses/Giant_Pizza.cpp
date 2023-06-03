#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Strongly Connected Components
struct sc_components {
  int n;
  vector<vector<int>> adj, adj_inv;
  vector<vector<int>> comps;
  vector<int> comp_ids;
  int num_comp = 0;
  sc_components(int n) : n(n), adj(n), adj_inv(n) {}

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
      for (int v : adj[u]) if (!vis[v]) self(self, v);
      order.push_back(u);
    };
    for (int i=0;i<n;i++) if(!vis[i]) topo_dfs(topo_dfs, i);
    reverse(begin(order), end(order));
    comp_ids.assign(n, 0);
    vis.assign(n, false);
    auto comp_dfs = [&](auto self, int u) -> void {
      vis[u] = true;
      comp_ids[u] = num_comp;
      comps.back().push_back(u);
      for (int v : adj_inv[u]) if (!vis[v]) self(self, v);
    };
    for (int i : order)
      if (!vis[i]) {
        comps.push_back({});
        comp_dfs(comp_dfs, i);
        num_comp++;
      }
  }
};

// 2 SAT implementation
struct two_sat {
  int n;
  vector<int> res;
  sc_components scc;

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
  void add(int a, int b) {
    scc.add(inv(a), b);
    scc.add(inv(b), a);
  }

  bool run() {
    scc.run();
  
    res.assign(n, -1);
    for (int i=scc.num_comp-1;i>=0;i--){
      for (int a : scc.comps[i]) {
        if (scc.comp_ids[a] == scc.comp_ids[inv(a)]) {
          return false;
        }
        if (res[norm(a)] == -1)
          res[norm(a)] = a < n;
      }
    }
    return true;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  two_sat ts(m);
  for (int i=0;i<n;i++){
    char a0,a1;
    int p0,p1;
    cin >> a0 >> p0 >> a1 >> p1;
    --p0,--p1;
    if (a0 == '-') {
      p0 = ts.inv(p0);
    }
    if (a1 == '-') {
      p1 = ts.inv(p1);
    }
    ts.add(p0, p1);
  }

  if (!ts.run()) {
    cout << "IMPOSSIBLE" << "\n";
    return 0;
  }
  for (int i=0;i<m;i++){
    if (ts.res[i]) {
      cout << "+ ";
    } else {
      cout << "- ";
    }
  }
}
