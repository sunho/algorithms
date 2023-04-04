#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  for (int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int inf = 1e9;
  vector dist(n, inf);
  vector p(n, 0);
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dist[v] == inf) {
        dist[v] = dist[u] + 1;
        p[v] = u;
        q.push(v);
      }
    }
  }
  if (dist[n-1] == inf) {
    cout << "IMPOSSIBLE" << "\n";
    return;
  }
  int v = n-1;
  stack<int> path;
  while (v != 0) {
    path.push(v);
    v = p[v];
  }
  path.push(0);
  cout << path.size() << "\n";
  while (!path.empty()) {
    int u = path.top();
    path.pop();
    cout << u + 1 << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
