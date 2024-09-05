#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  sort(begin(A),end(A));
  const int inf = 1e9;
  vector<map<int,int>> dp(2);
  dp[0][-inf-1] = 0;
  for (int i=0;i<n;i++){
    vector<map<int,int>> nxt(2);
    auto [l,r] = A[i];
    for (int j=0;j<2;j++){
      for (auto [x,d] : dp[j]) {
        if (j == 0) {
          nxt[1][x] = max(nxt[1][x], d);
        }
        int nxt_dp = x < l ? d + 1 : d;
        nxt[j][max(r, x)] = max(nxt[j][max(r,x)], nxt_dp);
      }
    }
    dp = nxt;
  }
  int ans = 0;
  for (auto [x,d] : dp[1]) {
    ans = max(ans, d);
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
