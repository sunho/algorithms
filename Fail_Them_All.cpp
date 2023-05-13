#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll = long long;

struct two_sat {
  int n;
  vector<int> res;

  vector<vector<bool>> adj;
  vector<vector<bool>> adj_inv;
  vector<vector<int>> comps;
  vector<int> comp_ids;
  int num_comp = 0;

  vector<int> order;
  vector<int> vis;
  two_sat(int n) : n(n), adj(2*n, vector<bool>(2*n)), adj_inv(2*n, vector<bool>(2*n)) {}

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
    adj[inv(a)][b] = true;
    adj[inv(b)][a] = true;
    adj_inv[b][inv(a)] = true;
    adj_inv[a][inv(b)] = true;
  }
  void remove(int a, int b){
    adj[inv(a)][b] = false;
    adj[inv(b)][a] = false;
    adj_inv[b][inv(a)] = false;
    adj_inv[a][inv(b)] = false;
  }

  void topo_dfs(int u) {
    vis[u] = true;
    for (int v=0;v<2*n;v++) {
      if (!adj[u][v]) continue;
      if (!vis[v]) topo_dfs(v);
    }
    order.push_back(u);
  }

  void comp_dfs(int u) {
    vis[u] = true;
    comp_ids[u] = num_comp;
    comps[num_comp].push_back(u);
     for (int v=0;v<2*n;v++) {
      if (!adj_inv[u][v]) continue;
      if (!vis[v]) comp_dfs(v);
    }
  }

  bool run() {
    vis.assign(n*2, false);
    for (int i=0;i<2*n;i++)
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


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  two_sat sat(m);
  for (int i=0;i<n;i++){
    string s;
    cin >> s;
    // reverse(s.begin(), s.end());
    for (int j=0;j<m;j++){
      for (int z=j+1;z<m;z++){
        if (s[j] == 'X' || s[z] == 'X') continue;
        int a = j, b = z;
        if (s[j] == 'F') a = sat.inv(a);
        if (s[z] == 'F') b = sat.inv(b);
        sat.add(sat.inv(a), sat.inv(b));
      }
    }
  }
  if (!sat.run()) {
    cout << -1 << "\n";
    return 0;
  }
  for (int i=0;i<m;i++){
    sat.add(sat.inv(i), sat.inv(i));
    if (!sat.run()) {
      sat.remove(sat.inv(i), sat.inv(i));
      cout << "T";
    } else {
      cout << "F";
    }
  }
  cout << 2001/3 + 2001/4 - 2001/12 - (2001/15 + 2001/20 - 2001/(60)) << "\n";
}
