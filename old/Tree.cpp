#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<vector<int>> adj(n);
  for (int i=0;i<m;i++){
    int u, v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (m != n-1) {
    cout << "graph" << "\n";
    return;
  }
  vector<int> vis(n);
  queue<int> q;
  q.push(0);
  vis[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (!vis[v]) {
        vis[v] = true;
        q.push(v);
      }
    }
  }
  if (all_of(begin(vis),end(vis),[](int x) { return x; })) {
    cout << "tree" << "\n";
  } else {
    cout << "graph" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
