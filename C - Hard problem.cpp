#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<array<string,2>> S(n, {"",""});
  for (int i=0;i<n;i++){
    cin >> S[i][0];
    S[i][1] = S[i][0];
    reverse(begin(S[i][1]),end(S[i][1]));
  }
  array<ll,2> dp = {0, A[0]};
  const ll inf = 1e18;
  for (int i=1;i<n;i++){
    array<ll,2> nxt = {inf, inf};
    for (int j=0;j<2;j++){
      for (int k=0;k<2;k++){
        if (S[i-1][j] <= S[i][k]) {
          nxt[k] = min(nxt[k], dp[j]+(k==1?A[i]:0));
        }
      }
    }
    dp = nxt;
  }
  ll ans = min(dp[0],dp[1]);
  if (ans == inf) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
