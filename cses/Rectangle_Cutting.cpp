#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  ll inf = 1e18;
  vector dp(n+1, vector<ll>(m+1, inf));
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      if (i != j) {
        for (int z=1;z<=i-1;z++){
          dp[i][j] = min(dp[i][j], dp[z][j] + dp[i-z][j] + 1);
        }
        for (int z=1;z<=j-1;z++){
          dp[i][j] = min(dp[i][j], dp[i][z] + dp[i][j-z] + 1);
        }
      } else {
        dp[i][j] = 0;
      }
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
