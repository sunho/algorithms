#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int M = N*(N+1)/2;
int16_t _dp[M*2+1][N][N];
auto dp = _dp + M + 1;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int m = n*(n-1)/2;
  const short inf = 1e4;
  for (int i=-m;i<=m;i++)
    for (int j=0;j<n;j++)
      for (int z=0;z<n;z++)
        dp[i][j][z] = inf;
  int cnt01 = 0, cnt10 = 0;
  int cnt0 = 0, cnt1 = 0;
  for (int i=n-1;i>=0;i--) {
    if (s[i] == '0') {
      cnt01 += cnt1;
      cnt0++;
    } else {
      cnt10 += cnt0;
      cnt1++;
    }
  }
  int R = cnt01 - cnt10;
  for (int i=0;i<n;i++)
    dp[R][i][i] = 0;
  for (int i=0;i<n-1;i++){
    if (s[i] == '0' && s[i+1] == '1')
      dp[R-2][i][i+1] = 1;
    else if (s[i] == '1' && s[i+1] == '0')
      dp[R+2][i][i+1] = 1;
    dp[R][i][i+1] = 0;
  }
  for (int k=2;k<=n;k++){
    for (int l=0;l<n;l++){
      int r = l + k;
      if (r >= n) continue;
      for (int z=-m;z<=m;z++) {
        dp[z][l][r] = min(dp[z][l][r-1], dp[z][l+1][r]);
        int cost = 2*(r-l+1)-2;
        if (s[l] == '0' && s[r] == '1') 
          if (z + cost <= m)
            dp[z][l][r] = min((int16_t)dp[z][l][r], (int16_t)(dp[z+cost][l+1][r-1]+1));
        
        if (s[l] == '1' && s[r] == '0') 
          if (z - cost >= -m)
            dp[z][l][r] = min(dp[z][l][r], (int16_t)(dp[z-cost][l+1][r-1]+1));
        
      }
    }
  }
  cout << dp[0][0][n-1] << "\n";
}
