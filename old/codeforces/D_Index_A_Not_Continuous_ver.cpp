#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,m;
  cin >> n >> m;

  vector<ll> A(n);
  for (int i=0;i<n;i++) cin >> A[i];

  const ll inf = 1e18;
  vector<ll> dp(m+1, -inf);
  dp[0] = 0;
  for (int i=0;i<n;i++){
    vector<ll> next = dp;
    for (int j=0;j<m;j++){
      next[j+1] = max(next[j+1], dp[j] + (j+1)*A[i]);
    }
    dp = move(next);
  }
  cout << dp[m] << "\n";
}
