#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n,m,h;
  cin >> n >> m >> h;
  vector adj_h(n+1, vector<int>(m));
  vector adj_w(n, vector<int>(m+1));
  for (int i=0;i<=n;i++){
    for (int j=0;j<m;j++){
      cin >> adj_h[i][j];
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<=m;j++){
      cin >> adj_w[i][j];
    }
  }
  priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

  for (int i=0;i<m;i++){
    if (adj_h[0][i] != -1) {
      pq.push({adj_h[0][i],0,i});
    }
    if (adj_h[n][i] != -1) {
      pq.push({adj_h[n][i],n-1,i});
    }
  }
  for (int i=0;i<n;i++){
    if (adj_w[i][0] != -1) {
      pq.push({adj_w[i][0],i,0});
    }
    if (adj_w[i][m] != -1) {
      pq.push({adj_w[i][m],i,m-1});
    }
  }
  vector<vector<int>> dist(n, vector<int>(m, -1));
  while (!pq.empty()) {
    auto [l, i, j] = pq.top();
    pq.pop();
    if (dist[i][j] != -1) continue;
    dist[i][j] = l;
    tuple<int,int,int> cands[] = {{adj_w[i][j], i,j-1}, {adj_w[i][j+1], i,j+1}, {adj_h[i][j], i-1,j}, {adj_h[i+1][j], i+1,j}};
    for (auto [w, u, v] : cands) {
      if (u < 0 || u >= n || v < 0 || v >= m || w == -1) continue;
      pq.push({max(w,l), u, v});
    }
  }

  ll ans = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (dist[i][j] == -1) ans += h;
      else ans += dist[i][j];
    }
  }
  cout << ans;
}
