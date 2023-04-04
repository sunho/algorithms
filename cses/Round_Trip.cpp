#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  for (int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector vis(n, 0);
  vector prd(n, -1);
  int s = -1;
  int t = -1;
  bool found = false;
  auto dfs = [&](int u, int p, auto&&self) -> void {
    vis[u] = 2;
    for (int v : adj[u]) {
      if (v == p) continue;
      if (vis[v] == 2) {
        stack<int> path;
        int cur = u;
        while (cur != v) {
          path.push(cur);
          cur = prd[cur];
        }
        path.push(v);
        cout << path.size() + 1 << "\n";
        while(!path.empty()){
          cout << path.top() + 1 << " ";
          path.pop();
        }
        cout << v + 1;
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
    if (!vis[i]) {
      dfs(i,-1,dfs);
    }
  }
  cout << "IMPOSSIBLE" << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
