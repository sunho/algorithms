#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 2 SAT implementation
struct two_sat {
  int n;
  vector<int> res;

  vector<vector<int>> adj;
  vector<vector<int>> adj_inv;
  vector<vector<int>> comps;
  vector<int> comp_ids;
  int num_comp = 0;

  vector<int> order;
  vector<int> vis;
  two_sat(int n) : n(n), adj(2*n), adj_inv(2*n) {}

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
    adj[inv(a)].push_back(b);
    adj[inv(b)].push_back(a);
    adj_inv[b].push_back(inv(a));
    adj_inv[a].push_back(inv(b));
  }

  void topo_dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
      if (!vis[v]) topo_dfs(v);
    }
    order.push_back(u);
  }

  void comp_dfs(int u) {
    vis[u] = true;
    comp_ids[u] = num_comp;
    comps[num_comp].push_back(u);
    for (int v : adj_inv[u]) {
      if (!vis[v]) comp_dfs(v);
    }
  }

  bool run() {
    vis.assign(n*2, false);
    for (int i=0;i<n*2;i++)
      if (!vis[i])
        topo_dfs(i);
    reverse(begin(order), end(order));

    vis.assign(n*2, false);
    comp_ids.assign(n*2, 0);
    for (int i : order) {
      if (!vis[i]) {
        comps.push_back({});
        comp_dfs(i);
        num_comp++;
      }
    }
  
    res.assign(n, -1);

    // Say C is early component and C' is later components
    // By SCC theorem we have edge (C,C') is only possible not
    // other way around. We will never get contradition (a<=>~a) 
    // by iterating components in reverse order.
    for (int i=num_comp-1;i>=0;i--){
      for (int a : comps[i]) {
        if (comp_ids[a] == comp_ids[inv(a)]) {
          return false;
        }
        if (res[norm(a)] == -1)
          res[norm(a)] = a < n;
      }
    }
    return true;
  }
};

bool solve() {
  int n,m;
  if (!(cin >> n >> m)) {
    return false;
  }

  two_sat sat(n);
  sat.add(0,0);
  for (int i=0;i<m;i++){
    int x, y;
    cin >> x >> y;
    if (x < 0) {
      x*=-1;
      --x;
      x = sat.inv(x);
    } else {
      --x;
    }
    if (y < 0) {
      y*=-1;
      --y;
      y = sat.inv(y);
    } else {
      --y;
    }
    sat.add(x,y);
  }
  if (sat.run()) {
    cout << "yes" << "\n";
  } else {
    cout << "no" << "\n";
  }
  return true;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  while (solve()) {}
}
