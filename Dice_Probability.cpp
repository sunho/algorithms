#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a >> b;
  vector<long double> dp(6*n+1);
  dp[0] = 1.0l;
  for (int i=0;i<n;i++){
    vector<long double> next(6*n+1);
    for (int j=1;j<=6*n;j++){
      for (int z=1;z<=6;z++){
        if (j - z < 0) continue;
        next[j] += dp[j-z] / 6.0l; 
      }
    }
    dp = move(next);
  }
  long double ans = 0;
  for (int i=a;i<=b;i++){
    ans += dp[i];
  }
  cout << fixed << setprecision(6) << ans << "\n";
}
