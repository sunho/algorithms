#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int b, n;
  cin >> b >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<vector<ld>> cost(n, vector<ld>(n));
  for (int i=0;i<n;i++){
    ll sum = 0;
    ll sum2 = 0;
    for (int j=i;j<n;j++){
      sum += A[j];
      sum2 += A[j]*A[j];
      int m = j-i+1;
      ld mean = (ld)sum / m;
      cost[i][j] = sum2 + mean*mean*m - 2*sum*mean;
    }
  }
  const ld inf = 1e9;
  vector<ld> dp(n+1, inf);
  dp[n] = 0;
  for (int i=0;i<b;i++){
    vector<ld> nxt(n+1, inf);
    nxt[n] = 0;
    for (int j=0;j<n;j++){
      for (int k=j;k<n;k++){
        nxt[j] = min(nxt[j], cost[j][k] + dp[k+1]);
      }
    }
    dp = nxt;
  }
  cout << fixed << setprecision(10) << dp[0] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
