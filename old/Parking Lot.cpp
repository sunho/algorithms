#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<char>> M(n, vector<char>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
    }
  }
  
  const double inf = 1e9;
  vector<vector<long double>> dp(n+1, vector<long double>(m+1, inf));
  dp[0][0] = 0;
  for (int i=0;i<=n;i++){
    for (int j=0;j<=m;j++){
      for (int x=i+1;x<=n;x++){
        for (int y=j+1;y<=m;y++){
          long double dist = sqrtl((ll)(x-i)*(x-i) + (ll)(y-j)*(y-j));
          bool ok = true;
          for (int k=0;k<x-i;k++){
            int ny = j + k*(y-j)/(x-i);
            if (M[i+k][ny] == '#') {
              ok = false;
            }
          }
          for (int k=0;k<y-j;k++){
            int nx = i + k*(x-i)/(y-j);
            if (M[nx][j+k] == '#') {
              ok = false;
            }
          }
          if (ok) {
            dp[x][y] = min(dp[x][y], dp[i][j] + dist);
          }
        }
      }
      if (i < n) {
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
      }
      if (j < m) {
        dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
      }
    }
  }
  cout << fixed << setprecision(14) << dp[n][m] << "\n";
}
