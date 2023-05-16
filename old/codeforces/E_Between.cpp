#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  vector<int> deg(n);
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    if (u == 0) continue;
    adj[v].push_back(u);
    deg[u]++;
  }
  int mx_level = 0;
  vector<int> levels(n);
  vector<vector<int>> words(n+1);
  queue<int> q;
  vector<bool> vis(n);
  for (int i=0;i<n;i++){
    if (deg[i] == 0) {
      if (i != 0) {
        cout << "INFINITE" << "\n";
        return;
      }
    }
  }
  q.push(0);
  vis[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    words[levels[u]].push_back(u);
    mx_level = max(mx_level, levels[u]);
    for (int v : adj[u]) {
      if (!vis[v]) {
        levels[v] = levels[u]+1;
        vis[v] = true;
        q.push(v);
      }
    }
  }
  for (int i=0;i<n;i++){
    if (!vis[i]) {
      cout << "INFINITE" << "\n";
      return;
    }
  }
  cout << "FINITE" << "\n";
  vector<int> ans;
  for (int i=0;i<=mx_level;i++){
    for (int j=mx_level;j>=i;j--){
      for (int v : words[j]) {
        ans.push_back(v);
      }
    }
  }
  cout << ans.size() << "\n";
  for (int v : ans) {
    cout << v + 1 << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
