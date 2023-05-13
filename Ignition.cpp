#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n,m;
  cin >> n >> m;

  vector<int> edges(m);
  vector adj(n, vector<pair<int,int>>());
  for (int i=0;i<m;i++){
    int u,v,d;
    cin >> u >> v >> d;
    --u,--v;
    edges[i] = d;
    adj[u].push_back({v,i});
    adj[v].push_back({u,i});
  }

  auto solve = [&](int s) -> int {
    vector<int> ignited(m, -1);
    vector<int> end(m,-1);
    vector<int> dist(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,s});
    int res = 0;
    while (!pq.empty()) {
      auto [t, u] = pq.top();
      pq.pop();
      if (dist[u] != -1)
        continue;
      dist[u] = t;
      for (auto [v, j] : adj[u]) {
        int w = edges[j];
        if (ignited[j] == -1) {
          ignited[j] = t;
          end[j] = (t+w)*10;
        } else {
          if (t < ignited[j] + w) {
            end[j] = t*10 + (w-(t-ignited[j]))*10/2;
          }
        }
        if (dist[v] == -1) {
          pq.push({t+w, v});
        }
      }
    }
    for (int v : end) {
      res = max(res, v);
    }
    return res;
  };
  int ans = 1e9;
  for (int i=0;i<n;i++){
    ans = min(ans, solve(i));
  }
  cout << ans / 10 << "." << ans % 10 << "\n";

}
