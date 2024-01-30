#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n);
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  vector<ll> dist(n, -1);
  pqg<pair<ll,int>> pq; 
  pq.push({0,1});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dist[u] != -1) continue;
    dist[u] = d;
    for (auto [v, w] : adj[u])  {
      if (dist[v] == -1) {
        pq.push({d+w,v});
      }
    }
  }
  vector<ll> dp(n, 0);
  dp[1] = 1;
  vector<int> id(n);
  iota(begin(id),end(id),0);
  sort(begin(id),end(id),[&](int i, int j) {
    return dist[i] < dist[j];
  });
  for (int i : id) {
    for (auto [v, _] : adj[i]) {
      if (dist[i] < dist[v])
        dp[v] += dp[i];
    }
  }
  cout << dp[0] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
