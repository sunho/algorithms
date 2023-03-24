#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  const ll inf = 1e18;
  vector dist(n, vector(n, inf));
  for(int i=0;i<n;i++){
    dist[i][i] = 0;
  }
  while(m--){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    --a,--b;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
  }
  for (int t=0;t<n;t++){
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        dist[i][j] = min(dist[i][j], dist[i][t] + dist[t][j]);
      }
    }
  }
  while(q--) {
    int a,b;
    cin >> a >> b;
    --a,--b;
    if (dist[a][b] == inf) {
      cout << -1 << "\n";
    } else {
      cout << dist[a][b] << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
