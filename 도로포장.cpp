#include <bits/stdc++.h>
#include <queue>

using namespace std;
using ll = long long;

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<pair<int,int>>> adj(n);
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> pq;
  vector<vector<ll>> dist(n, vector<ll>(k+1, -1));
  pq.push({0,0,k});
  while (!pq.empty()) {
    auto [d,u,r] = pq.top();
    pq.pop();
    if (dist[u][r] != -1) continue;
    dist[u][r] = d;
    for (auto [v,w] : adj[u]) {
      pq.push({d+w,v,r});
      if (r != 0) {
        pq.push({d,v,r-1});
      }
    }
  }
  ll ans = 1e18;
  for (int i=0;i<=k;i++) {
    ans = min(ans,dist[n-1][i]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
