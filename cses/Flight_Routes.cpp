#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  vector adj(n, vector<pair<int,int>>());
  while(m--){
    int a,b,w;
    cin >> a >> b >> w;
    --a,--b;
    adj[a].push_back({b,w});
  }
  ll inf = 1e18;
  vector dist(n, array<ll, 10>());
  for (int i=0;i<n;i++){
    for (int j=0;j<k;j++){
      dist[i][j] = inf;
    }
  }
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
  pq.push({0,0});
  while (!pq.empty()){
    auto [d, u] = pq.top();
    pq.pop();
    for (int i=0;i<k;i++){
      if (dist[u][i] == inf) {
        dist[u][i] = d;
        for (auto [v, w] : adj[u]) {
          pq.push({d+w,v});
        }
        break;
      }
    }
  }
  for (int i=0;i<k;i++){
    cout << dist[n-1][i] << " ";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
