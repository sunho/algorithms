#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  vector<set<int>> adj(k);
  vector<int> self(k);
  vector<int> deg(k);
  set<int> cands;
  for (int i=0;i<n;i++) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    if (u != v) {
      if (!adj[v].count(u)){
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++;
        deg[v]++;
      }
    } else {
      self[u] = true;
    }
    cands.insert(u);
    cands.insert(v);
  }
  vector<int> to_del;
  for (int i=0;i<k;i++){
    if (deg[i] == 1 && !self[i]) {
      to_del.push_back(i);
    }
  }
  for (int i : to_del) {
    if (deg[*adj[i].begin()] != 1){
      cands.erase(i);
      deg[*adj[i].begin()]--;
      adj[*adj[i].begin()].erase(i);
    }
  }

  set<int> vis;
  int comps = 0;
  bool ok = true;
  auto dfs = [&](auto&&self, int u) {
    if (vis.count(u)) { return; }
    vis.insert(u);
    for (int v : adj[u]) {
      self(self, v);
    }
  };
  for (int c : cands) {
    if (deg[c] > 2) {
      ok = false;
    }
    if (deg[c] == 1) {
      dfs(dfs, c);
      comps=1;
    } else if (deg[c] == 0) {
      assert(self[c]);
      vis.insert(c);
      comps=1;
    }
  }
  if (comps == 0) {
    for (int c : cands) {
      if (deg[c] != 2) {
        ok = false;
      }
    }
    dfs(dfs, *cands.begin());
    if (ok && vis.size() == cands.size()) {
      cout << "possible" << "\n";
      return 0;
    }
    cout << "impossible" << "\n";
  } else {
    if (ok && cands.size() == vis.size()) {
      cout << "possible" << "\n";
      return 0;
    }
    cout << "impossible" << "\n";
  }
  
}
