#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  while (m--){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
  }
  
  vector<int> vis(n);
  vector<int> prd(n);
  auto dfs = [&](int u, int p, auto&& self) -> void {
    vis[u] = 2;
    for (int v : adj[u]) {
      if (vis[v] == 2) {
        int cur = u;
        vector<int> path;
        path.push_back(v);
        while (cur != v) {
          path.push_back(cur);
          cur = prd[cur];
        }
        path.push_back(v);
        reverse(begin(path), end(path));
        cout << path.size() << "\n";
        for (int v : path) {
          cout << v + 1 << " ";
        }
        exit(0);
      } else if (vis[v] == 1) {
        continue;
      }
      prd[v] = u;
      self(v,u,self);
    }
    vis[u] = 1;
  };
  for (int i=0;i<n;i++){
    if (!vis[i])
      dfs(i,-1,dfs);
  }
  cout << "IMPOSSIBLE" << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
