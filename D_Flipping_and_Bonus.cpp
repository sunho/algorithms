#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  ll inf = 1e18;
  vector<ll> dp(n+1, -inf);
  dp[0] = 0;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  vector<ll> bonus(n+1);
  for (int i=0;i<m;i++){
    int k,x;
    cin >> k >> x;
    bonus[k] += x;
  }
  for (int i=0;i<n;i++){
    vector<ll> next(n+1, -inf);
    for (int j=0;j<n;j++){
      next[j+1] = max(next[j+1], dp[j] + bonus[j+1] + A[i]);
      next[0] = max(next[0], dp[j]);
    }
    dp = move(next);
  }
  ll ans = -inf;
  for (int i=0;i<=n;i++){
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";

}
