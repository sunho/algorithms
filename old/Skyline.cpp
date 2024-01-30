#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> bool ckmin(T&a, const T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T&b) { bool B = a < b; a = max(a,b); return B; }

void solve() {
  int n;
  cin >> n;
  vector<int> H(n);
  for (int i=0;i<n;i++){
    cin >> H[i];
  }
  const int N = 200;
  const ll inf = 1e18;
  vector<vector<ll>> dp(N+1, vector<ll>(N+1,inf));
  dp[0][0] = 0;
  for (int i=0;i<n+3;i++){
    vector<vector<ll>> nxt(N+1, vector<ll>(N+1,inf));
    for (int j=N;j>=0;j--){
      for (int k=N;k>=0;k--){
        array<int, 3> a = {j,k,i<n?H[i]:0};
        int d = min({a[0],a[1],a[2]});
        int d2 = min({a[0],a[1]});
        int d3 = min({a[0]-d,a[1]-d});
        ckmin(nxt[a[1]-d-d3][a[2]-d], dp[j][k] + d*7 + d3*5 + (a[0]-d-d3)*3);
        if (a[0] == 0) {
          ckmin(nxt[a[1]][a[2]], dp[j][k]);
        }
        if (d2 > 0) {
          ckmin(dp[a[0]-1][a[1]-1], dp[j][k] + 5);
        }
        if (a[0] > 0) {
          ckmin(dp[a[0]-1][a[1]], dp[j][k] + 3);
        }
        if (a[1] > 0) {
          ckmin(dp[a[0]][a[1]-1], dp[j][k] + 3);
        }
      }
    }
    dp = nxt;
  }
  cout << dp[0][0] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
