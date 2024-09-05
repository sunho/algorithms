#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, X, F;
  cin >> n >> X >> F;
  vector<tuple<int,int,int>> A(n);
  for (int i=0;i<n;i++){
    int x,p,a;
    cin >> x >> p >> a;
    A[i] = {x,p,a};
  }
  A.push_back({X,0,0});
  const int inf = 1e9;
  vector<int> dp(F+1, inf);
  dp[0] = 0;
  for (int i=0;i<=n;i++){
    vector<int> next(F+1, inf);
    int dist = i != 0 ? get<0>(A[i]) - get<0>(A[i-1]) : 0;
    auto [_,c,w] = A[i];
    for (int j=dist;j<=F;j++) {
      for (int k=0;k<=w;k++){
        if (j-dist+k <= F) {
          next[j-dist+k] = min(next[j-dist+k],dp[j]+c*k);
        }
      }
    }
    dp = next;
  }
  int ans = *min_element(begin(dp),end(dp));
  if (ans == inf) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
