#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector M(n, vector(m, ' '));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
    }
  }
  vector vis(n, vector(m, false));
  auto dfs = [&](int i, int j, auto&&self) -> void {
    vis[i][j] = true;
    pair<int,int> cands[] = {{i+1,j}, {i-1,j}, {i,j+1}, {i,j-1}};
    for (auto [x,y] : cands) {
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      if (vis[x][y]) continue;
      if (M[x][y] == '#') continue;
      self(x,y,self);
    }
  };
  int ans = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (!vis[i][j] && M[i][j] == '.') {
        ans++;
        dfs(i,j,dfs);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
