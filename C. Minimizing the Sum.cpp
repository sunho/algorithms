#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  const ll inf = 1e18;
  vector<vector<ll>> dp(n+1, vector<ll>(k+1, inf));
  dp[0][0] = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<=k;j++){
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]+A[i]);
    }
    for (int j=0;j<=k;j++){
      int mn = A[i];
      for (int z=1;z<=k-j;z++){
        if (i+z+1 > n) continue;
        mn = min(mn, A[i+z]);
        dp[i+z+1][j+z] = min(dp[i+z+1][j+z], dp[i][j]+(ll)mn*(z+1));
      }
    }
  }
  ll ans = inf;
  for (int i=0;i<=k;i++){
    ans = min(ans, dp[n][i]);
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
