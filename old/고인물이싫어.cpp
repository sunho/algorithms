#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int h,w;
  cin >> h >> w;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> A[i][j];
    }
  }
  vector<vector<int>> B(n, vector<int>(m));
  queue<pair<int,int>> q;
  int k;
  cin >> k;
  while (k--) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    B[u][v] = 1;
    q.push({u,v});
  }
  while (!q.empty()) {
    auto [u,v] = q.front();
    q.pop();
    pair<int,int> cands[] = {{u-1,v},{u+1,v},{u,v-1},{u,v+1}};
    for (auto [x,y] : cands) {
      if (x < 0 || x >= n || y < 0 || y >= m) {
        continue;
      }
      if (A[u][v] > A[x][y]) continue;
      if (B[x][y] == 0) {
        B[x][y] = 1;
        q.push({x,y});
      }
    }
  }
  vector<vector<int>> pf(n+1, vector<int>(m+1));
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + B[i-1][j-1];
    }
  }
  int ans = 0;
  for (int i=0;i<=n-h;i++){
    for (int j=0;j<=m-w;j++){
      int q = pf[i+h][j+w] - pf[i+h][j] - pf[i][j+w] + pf[i][j];
      if (q == h*w) {
        ans ++;
      }
    }
  }
  cout << ans << "\n";
}
