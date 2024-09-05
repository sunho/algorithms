#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int N = 2700;
  vector<int> dp(2*N+1, N);
  dp[0] = 0;
  vector<int> C = {1,3,6,10,15};
  for (int i=1;i<=2*N;i++){
    for (int c : C) {
      if (i-c >= 0) {
        dp[i] = min(dp[i], dp[i-c]+1);
      }
    }
  }
  int x;
  cin >> x;
  if (x > N) {
    int h = N+(x-N)%N;
    cout << dp[h] + ((x-h)/N)*dp[N] << "\n";
  } else {
    cout << dp[x] << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
