#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<long double> dp(k+1, 1.0l/k);
  for (int i=0;i<n-1;i++){
    vector<long double> next(k+1, 0.0);
    for (int j=1;j<=k;j++){
      for (int z=1;z<j;z++){
        next[j] += dp[z]/k;
      }
      next[j] += j*dp[j]/k;
    }
    dp = move(next);
  }
  long double ans = 0;
  for (int i=1;i<=k;i++) {
    ans += dp[i] * i;
  }
  cout << setprecision(6) << fixed << ans << "\n";
}
