#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s,t;
  cin >> s >> t;
  swap(s,t);
  int n = s.size(), m = t.size();
  int inf = 1e9;
  vector dp(n+1, vector(m+1, inf));
  for (int i=0;i<=n;i++){
    for (int j=0;j<=m;j++){
      if (i == 0) {
        dp[i][j] = j;
        continue;
      }
      if (j >= 1) {
        if (s[i-1] == t[j-1]) {
          dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
        } else {
          dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j]);
        }
        dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
      }
      dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
    }
  }
  cout << dp[n][m] << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
