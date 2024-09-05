#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll x;
  cin >> x;
  const int inf = 1e9;
  vector<int> dp(100, inf);
  dp[0] = 0;
  for (int i=1;i<=99;i++){
    dp[i] = dp[i-1] + 1;
    if (i - 25 >= 0) {
      dp[i] = min(dp[i], dp[i-25]+1);
    }
    if (i - 10 >= 0) {
      dp[i] = min(dp[i], dp[i-10]+1);
    }
  }
  int ans = 0;
  while (x) {
    ans += dp[x%100];
    x /= 100;
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
