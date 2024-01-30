#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  const ll inf = 1e18;
  const int m = 3*n;
  vector<ll> dp(n+1, inf);
  dp[0] = 0;
  for (int i=0;i<m;i++){
    for (int j=n;j>=1;j--) {
      dp[j] = min(dp[j], dp[j-1] + abs(A[j-1]-(i+1)));
    }
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
