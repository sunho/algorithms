#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  for(int i=0;i<n;i++){
    cin >> B[i];
  }
  auto go = [&]() {
    const ll inf  = 1e18;
    vector<array<array<ll,2>,2>> dp(n+1,{inf,inf,inf,inf});
    dp[0][0][0] = 0;
    dp[0][1][1] = 0;
    for(int i=0;i<n;i++){
      for(int j=0;j<2;j++) {
        for(int k=0;k<2;k++) {
          int bias = j == 0 ? A[i] : 0;
          if (i != n-1) {
            ckmin(dp[i+1][j^1][k], dp[i][j][k] + bias);
            ckmin(dp[i+1][j][k], dp[i][j][k] + B[i] + bias);
          } else {
            if (j == k) {
              ckmin(dp[i+1][j][k], dp[i][j][k] + B[i] + bias);
            } else {
              ckmin(dp[i+1][j][k], dp[i][j][k] + bias);
            }
          }
        }
      }
    }
    ll res = inf;
    for(int i=0;i<2;i++) {
      for(int j=0;j<2;j++) {
        ckmin(res, dp[n][i][j]);
      }
    }
    return res;
  };
  ll ans = go();
  rotate(A.begin(), A.begin() +n-1, A.end());
  rotate(B.begin(), B.begin() +n-1, B.end());
  ans = min(ans, go());
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
