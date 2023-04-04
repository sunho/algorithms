#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector adj(n, vector<int>());

  while (m--) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  const int inf = (int)1e9+1;

  auto calc = [&](int start) {
    queue<pair<int,int>> q;
    q.push({start,-1});
    vector<int> dist(n,-1);
    dist[start] = 0;
    int res = inf;
    while (!q.empty()) {
      auto [u,p] = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (v == p) continue;
        if (dist[v] == -1) {
          dist[v] = dist[u]+1;
          q.push({v,u});
        } else {
          res = min(res, dist[v] + dist[u]+1);
        }
      }
    }
    return res;
  };
  int ans = inf;
  for (int i=0;i<n;i++){
    ans = min(ans, calc(i));
  }

  if (ans == inf) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}
