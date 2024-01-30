#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  const int inf = 1e9;
  vector<int> A(m);
  for (int i=0;i<m;i++) {
    cin >> A[i];
  }
  vector<int> pos(n+1);
  for (int i=0;i<m;i++){
    pos[A[i]] = 1;
    for (int j=i+1;j<m;j++){
      if (A[i] + A[j] <= n) {
        pos[A[i]+A[j]] = true;
      }
    }
  }
  vector<int> dp(n+1, inf);
  dp[0] = 0;
  for (int d=n;d>=1;d--){
    if (!pos[d]) continue;
    for (int i=d;i<=n;i++){
      dp[i] = min(dp[i], dp[i-d]+1);
    }
  }
  if (dp[n] == inf) {
    cout << -1 << "\n";
  } else {
    cout << dp[n] << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
