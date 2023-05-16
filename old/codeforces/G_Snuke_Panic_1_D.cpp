#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  

  const int N = 1e5;
  map<int,pair<int,int>> snukes;
  for (int i=0;i<n;i++){
    int t,j,a;
    cin >> t >> j >> a;
    snukes[t] = {j,a};
  }

  const ll inf = 1e18;
  vector<array<ll,5>> dp(N+1, {-inf,-inf,-inf,-inf,-inf});
  dp[0][0] = 0;
  for (int t=1;t<=N;t++){
    if (snukes.count(t)) {
      auto [j, a] = snukes[t];
      for (int k=0;k<=4;k++){
        if (t-k < 0) continue;
        for (int d=0;d<=k;d++){
          if (j+d <= 4) {
            dp[t][j] = max(dp[t][j], dp[t-k][j+d] + a);
          }
          if (j-d >= 0) {
            dp[t][j] = max(dp[t][j], dp[t-k][j-d] + a);
          }
        }
      }
    }
    for (int j=0;j<=4;j++) {
      dp[t][j] = max(dp[t][j], dp[t-1][j]);
    }
  }
  ll ans = -inf;
  for (int i=0;i<=4;i++)
    ans = max(ans, dp[N][i]);
  cout << ans << "\n";
}
