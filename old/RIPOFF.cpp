#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int n, int m, int k) {
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  const ll inf = 1e18;
  vector<ll> dp(n+2, -inf);
  ll ans = -inf;
  dp[0] = 0;
  for (int i=0;i<k;i++){
    vector<ll> nxt(n+2, -inf);
    for (int i=0;i<=n;i++){
      for (int j=1;j<=m;j++){
        nxt[min(i+j,n+1)] = max(nxt[min(i+j,n+1)], dp[i] + (i+j<=n ? A[i+j-1] : 0));
      }
    }
    ans = max(ans, nxt[n+1]);
    dp = nxt;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,m,k;
  while (cin >> n >> m >> k) {
    solve(n,m,k);
  }
}
