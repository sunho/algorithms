#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  const int MOD = 100999;
  int n;
  cin >> n;
  vector<ll> dp(n+1);
  dp[0] = 1;
  for (int i=1;i<=n;i++){
    vector<ll> nxt = dp;
    for (int j=0;j<n;j++) {
      if (i+j<=n) {
        nxt[i+j] += dp[j];
        nxt[i+j] %= MOD;
      }
    }
    dp = nxt;
  }
  cout << dp[n] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
