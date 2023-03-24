#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  while(m--){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
  }
  vector<int> vis(n);
  vector<int> order;
  auto dfs = [&](int u, auto && self) -> void {
    vis[u] = true;
    for (int v : adj[u]) {
      if (vis[v]) continue;
      self(v, self);
    }
    order.push_back(u);
  };
  dfs(0, dfs);
  if (!vis[n-1]) {
    cout << "IMPOSSIBLE" << "\n";
    return;
  }
  reverse(begin(order), end(order));
  vector<int> dp(n,0);
  vector<int> prd(n, 0);
  for (int i : order) {
    for (int v : adj[i]) {
      if (dp[v] < dp[i] + 1) {
        dp[v] = dp[i] + 1;
        prd[v] = i;
      }
    }
  }
  vector<int> path;
  int cur = n-1;
  while (cur != 0) {
    path.push_back(cur);
    cur = prd[cur];
  }
  path.push_back(0);
  reverse(begin(path), end(path));
  cout << path.size() << "\n";
  for (int v : path) {
    cout << v + 1 << " ";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  
  return 0;
}
