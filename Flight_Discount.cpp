#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector adj(n, vector<pair<int,int>>());
  for (int i=0;i<m;i++){
    int a,b,w;
    cin >> a >> b >> w;
    --a,--b;
    adj[a].push_back({b,w});
  }
  ll inf = 1e18;
  vector dist(n, array{inf,inf});
  set<tuple<ll,int,int>> pq;
  pq.insert({0,0,0});
  while (!pq.empty()) {
    auto [d, u, used] = *pq.begin();
    pq.erase(pq.begin());
    if (dist[u][used] != inf) {
      continue;
    }
    dist[u][used] = d;
    for (auto [v,w] : adj[u]) {
      if (!used && dist[v][1] == inf)
        pq.insert({d+w/2, v, 1});
      if (dist[v][used] == inf)
        pq.insert({d+w, v, used});
    }
  }
  cout << dist[n-1][1] << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
