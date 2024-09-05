#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> A(4);
  for (int i=0;i<n;i++){
    int w,a;
    cin >> w >> a;
    A[w].push_back(a);
  }
  for (int i=0;i<4;i++){
    sort(rbegin(A[i]),rend(A[i]));
  }
  const ll inf = 1e18;
  vector<tuple<ll,int,int>> dp(m+1, {-inf,0,0});
  dp[0] = {0,0,0};
  for (int i=1;i<=m;i++){
    {
      auto [x, c1, c2] = dp[i-1];
      if (c1 < (int)A[1].size()) {
        dp[i] = max(dp[i], {x + A[1][c1], c1+1, c2});
      }
      dp[i] = max(dp[i], {x, c1, c2});
    }
    {
      if (i - 2 >= 0) {
        auto [x, c1, c2] = dp[i-2];
        if (c2 < (int)A[2].size()) {
          dp[i] = max(dp[i], {x + A[2][c2], c1, c2+1});
        }
      }
    }
  }
  ll ans = 0;
  ll sum = 0;
  for (int i=0;i<=min(m/3,(int)A[3].size());i++){
    ans = max(ans,get<0>(dp[m-3*i])+sum);
    if (i < (int)A[3].size()){
      sum += A[3][i];
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
