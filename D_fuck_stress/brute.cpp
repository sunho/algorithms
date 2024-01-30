#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  ll sum = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    sum += A[i];
  }
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  ll ng = 0, ok = sum+1;
  auto check = [&](ll cost) {
    vector<ll> dp(cost+1, 0);
    dp[0] = 0;
    for (int i=0;i<n;i++){
      int k = upper_bound(begin(pf),end(pf),cost+pf[i])-begin(pf)-1;
      if (k > i) {
        dp[min(k+1,n)] = max(dp[min(k+1,n)], dp[i] + pf[k]-pf[i]);
      }
      dp[i+1] = max(dp[i], dp[i+1]);
    }
    return sum - dp[n] <= cost;
  };
  for (ll i = ng; i<= ok; i++) {
    if (check(i)) {
      cout << i << "\n";
      return;
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
