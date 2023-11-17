#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  int n,c;
  cin >> n >> c;
  vector<vector<ll>> X(n, vector<ll>(c+1));
  vector<vector<ll>> dp(n+1, vector<ll>(c+1));
  vector<int> A(n);
  vector<int> B(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  for (int i=0;i<n;i++) {
    cin >> B[i];
  }
  for (int i=0;i<n;i++) {
    for (int a=A[i];a<=B[i];a++) {
      ll cur = 1;
      for (int j=0;j<=c;j++) {
        X[i][j] += cur;
        X[i][j] %= MOD;
        cur = cur * a % MOD;
      }
    }
  }
  dp[0][0] = 1;
  for (int i=1;i<=n;i++){
    for (int j=0;j<=c;j++) {
      for (int k=0;k<=j;k++){
        dp[i][j] += dp[i-1][j-k]*X[i-1][k] % MOD;
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[n][c] << "\n";
}
