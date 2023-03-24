#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int,int,int>> edges(m);
  for (int i=0;i<m;i++){
    int a,b,w;
    cin >> a >> b >> w;
    --a,--b;
    edges[i] = {a,b,w};
  }
  ll inf = 1e18;
  vector<ll> dist(n, 0);
  vector<int> p(n,-1);
  int x;
  for (int t=0;t<n;t++){
    for (int i=0;i<m;i++){
      auto [a,b,w] = edges[i];
      if (dist[b] > dist[a]+w) {
        p[b] = a;
        dist[b] = dist[a]+w;
      }
    }
  }
  for (int i=0;i<m;i++){
    auto [a,b,w] = edges[i];
    if (dist[b] > dist[a]+w) {
      cout << "YES" << "\n";
      int v = p[a];
      for (int i=0;i<n;i++){
        v = p[v];
      }
      int w = p[v];
      stack<int> path;
      while (w != v) {
        path.push(w);
        w = p[w];
      }
      cout << v + 1 << " ";
      while (!path.empty()) {
        int k = path.top();
        path.pop();
        cout << k + 1 << " ";
      }
      cout << v + 1 << " ";
      cout << "\n";
      return;
    }
  }
  cout << "NO" << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
