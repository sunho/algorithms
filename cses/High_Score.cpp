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
  vector<ll> dist(n, -inf);
  dist[0] = 0;
  for (int t=0;t<n;t++){
    for (int i=0;i<m;i++){
      auto [a,b,w] = edges[i];
      if (dist[a] != -inf)
        dist[b] = max(dist[b], dist[a]+w);
    }
  }
  vector<bool> neg(n,false);
  for (int t=0;t<n;t++){
    for (int i=0;i<m;i++){
      auto [a,b,w] = edges[i];
      if (dist[a] != -inf && dist[b] < dist[a]+w) {
        neg[a] = true;
      }
      neg[b] = neg[b] || neg[a];
    }
  }
  if (neg[n-1]){
    cout << -1 << "\n";
  } else {
    cout << dist[n-1] << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
