#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,x;
  cin >> n >> x;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
  }
  const int inf = 1e9;
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(x, inf)));
  vector<vector<vector<int>>> dp2(n, vector<vector<int>>(n, vector<int>(x, inf)));
  for (int l=0;l<n;l++){
    for (int k=0;k<x;k++){
      if (k == A[l]) {
        dp[l][l][k] = 0;
        dp2[l][l][k] = 1;
      } else {
        dp2[l][l][k] = 0;
        dp[l][l][k] = 1;
      }
    }
  }
  for (int s=2;s<=n;s++){
    for (int l=0;l<n-s+1;l++){
      int r = l+s-1;
      for (int k=0;k<x;k++){
        if (A[l] == k) {
          dp[l][r][k] = min(dp[l][r][k], dp[l+1][r][k]);
        } else {
          dp2[l][r][k] = min(dp2[l][r][k], dp2[l+1][r][k]);
        }
        if (A[r] == k) {
          dp[l][r][k] = min(dp[l][r][k], dp[l][r-1][k]);
        } else {
          dp2[l][r][k] = min(dp2[l][r][k], dp2[l][r-1][k]);
        }
        for (int i=l;i<r;i++){
          dp[l][r][k] = min(dp[l][r][k],dp[l][i][k]+dp[i+1][r][k]);
          dp2[l][r][k] = min(dp2[l][r][k],dp2[l][i][k]+dp2[i+1][r][k]);
        }
      }
      for (int k=0;k<x;k++){
        for (int m=0;m<x;m++){
          if (k == m) {
            dp[l][r][k] = min(dp[l][r][k], dp2[l][r][m]+1);
          }
          if (k != m) {
            dp2[l][r][k] = min(dp2[l][r][k], dp[l][r][m]);
          }
        }
      }
    }
  }
  int ans = inf;
  for (int i=0;i<x;i++){
    ans = min(ans, dp[0][n-1][i]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
