#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<ll> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  ll ans = 0;
  ll inf = 1e18;
  vector<ll> dp(k+1, -inf);
  dp[0] = 0;
  for (int i=0;i<n;i++) {
    vector<ll> nxt(k+1, -inf);
    for (int j=0;j<=k;j++){
      nxt[j] = max(nxt[j], max(dp[j] + A[i] - x,0ll));
    }
    for (int j=0;j<k;j++){
      nxt[j+1] = max(nxt[j+1], max(dp[j] + A[i] + x, 0ll));
    }
    dp = nxt;
    ans = max(ans, dp[k]);
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
