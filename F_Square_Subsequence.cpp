#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;

  const int MOD = 998244353;


  ll ans = 0;
  int n = s.size();
  for (int m=1;m<n;m++){
    int k = n-m;
    vector<vector<array<ll,2>>> dp(m+1, vector<array<ll,2>>(k+1, {0,0}));
    dp[0][0][0] = 1;
    for (int i=0;i<m;i++){
      for (int j=0;j<k;j++){
        dp[i+1][j][0] += dp[i][j][0];
        dp[i+1][j][0] %= MOD;
        // dp[i][j+1][0] += dp[i][j][0];
        // dp[i][j+1][0] %= MOD;
        if (s[i] == s[m+j]) {
          dp[i+1][j+1][0] += dp[i][j][0];
          dp[i+1][j+1][0] %= MOD;
          if (i+1 == m) {
            dp[i+1][j+1][1] += dp[i][j][0];
            dp[i+1][j+1][1] %= MOD;
          }
        }
      }
    }
    ans = ans + dp[m][k][1] % MOD;
  }
  cout << ans;

}
