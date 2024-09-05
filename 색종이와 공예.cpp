#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<char>> A(n, vector<char>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> A[i][j];
    }
  }
  vector<vector<char>> vis(n, vector<char>(m));
  bool ok = true;
  auto bfs = [&](int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = true;
    int mx = x, my = y;
    int nx = x, ny = y;
    int cnt = 0;
    while (!q.empty()) {
      auto [u,v] = q.front();
      q.pop();
      mx = max(mx, u);
      my = max(my, v);
      nx = min(nx, u);
      ny = min(ny, v);
      cnt++;
      pair<int,int> adj[] = {{u,v+1},{u,v-1},{u-1,v},{u+1,v}};
      for (auto [i,j] : adj) {
        if (i < 0 || i >= n || j < 0 || j >= m) continue;
        if (vis[i][j]) continue;
        if (A[i][j] != A[x][y]) continue;
        vis[i][j] = true;
        q.push({i,j});
      }
    }
    if ((mx-nx+1)*(my-ny+1) != cnt)
      ok = false;
  };
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (!vis[i][j]) {
        bfs(i,j);
      }
    }
  }
  if (ok) {
    cout << "dd";
  } else {
    cout << "BaboBabo";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
