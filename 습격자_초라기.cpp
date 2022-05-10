#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  const int inf = 1e9;
  int n, w;
  cin >> n >> w;
  vector<vector<int>> A(n, vector<int>(2));
  for(int i=0;i<2;i++) {
    for(int j=0;j<n;j++) {
      cin >> A[j][i];
    }
  }
  auto go = [&]() {
    array<array<array<int, 3>,2> dp;
    for(auto& r : dp) for (auto& c : r) c.fill(inf);
    for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
        dp[j][1][i] = 0;
      }
    }
    for(int i=1;i<=n;i++) {
      for (int k=0;k<3;k++) {
        array<array<int, 3>,2> next;
        for(auto& r : next) r.fill(inf);
        auto& cdp = dp[k];
        next[0] = cdp[1];
        array<int, 2> mdp = {min({cdp[0][0], cdp[0][1], cdp[0][2]}), min({cdp[1][0], cdp[1][1], cdp[1][2]})};
        if (A[i-1][0] + A[i-1][1] <= w && (k == 0 || i != 1)) {
          ckmin(next[1][0], mdp[1] + 1);
        } else {
          ckmin(next[1][0], mdp[1] + 2);
        }
        if (i >= 2) {
          int a = A[i-2][0] + A[i-1][0];
          int b = A[i-2][1] + A[i-1][1];
          if (a <= w && b <= w  && (k == 0 || i != 2)) ckmin(next[1][0], mdp[0] + 2);
          if (a<=w && (k != 2 || i != 2)) ckmin(next[1][1], mdp[0] + 3);
          if (b<=w && (k != 1 || i != 2)) ckmin(next[1][2], mdp[0] + 3);
        }
        if (i >= 3) {
          pair<int,int> a = {A[i-2][0] + A[i-1][0], A[i-3][1] + A[i-2][1]};
          pair<int,int> b = {A[i-3][0] + A[i-2][0], A[i-2][1] + A[i-1][1]};
          if (a._0 <= w && a._1 <= w) ckmin(next[1][1], cdp[1][2] + 1);
          if (b._0 <= w && b._1 <= w) ckmin(next[1][2], cdp[1][1] + 1);
        }
      }
    }
    int res = min({dp[0][1][0], dp[0][1][1], dp[0][1][2]});
    if (n > 2) {
      pair<int,int> a {A[n-1][0] + A[0][0], A[n-2][1] + A[n-1][1]};
      if (a._0 <= w && a._1 <= w) ckmin(res, dp[2][1][2]-1);
      pair<int,int> b {A[n-2][0] + A[n-1][0], A[n-1][1] + A[0][1]};
      if (b._0 <= w && b._1 <= w) ckmin(res, dp[1][1][1]-1);
    }
    return res;
  };
  int ans = go();
  if (n == 1) {
    cout << ans << "\n";
    return;
  }
  rotate(A.begin(), A.begin()+1, A.end());
  ans = min(ans, go());
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}