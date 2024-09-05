#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> deg(n);
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++,deg[v]++;
  }
  vector<int> vis(n);
  queue<int> q;
  for (int i=0;i<n;i++){
    if (deg[i] == 1) {
      q.push(i);
      deg[i]--;
    }
  }

  vector<int> P(n);
  iota(begin(P),end(P),0);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (int v : adj[a]) {
      deg[v]--;
      if (deg[v] == 1) {
        q.push(v);
      }
    }
    if (q.empty()) break;
    int b = q.front();
    q.pop();
    swap(P[a], P[b]);
    for (int v : adj[b]) {
      deg[v]--;
      if (deg[v] == 1) {
        q.push(v);
      }
    }
  }
  for (int i=0;i<n;i++){
    cout << P[i] + 1 << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
