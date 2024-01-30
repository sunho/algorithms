#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> A(n);
  ll sum = 0;
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    sum += A[i].first;
  }
  const ll inf = 1e18;
  vector<ll> dp(m+1,-inf);
  dp[0] = 0;
  for (int i=0;i<n;i++){
    auto [x,y] = A[i];
    for (int j=m;j>1;j--){
      if (j-y-1 >= 0)
        dp[j] = max(dp[j], dp[j-y-1]+2*x);
      if (j-y >= 0)
        dp[j] = max(dp[j], dp[j-y]+x);
    }
  }
  ll mx = -inf;
  for (int i=0;i<=m;i++){
    mx = max(mx, dp[i]);
  }
  if (mx - sum == 0) {
    cout << "D";
  } else if (mx - sum > 0) {
    cout << "W";
  } else {
    cout << "L";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
