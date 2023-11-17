#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n,m,q;
  cin >> n >> m >> q;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> A[i][j];
    }
  }
  vector<vector<ll>> dp(n, vector<ll>(m));
  for (int j=0;j<m;j++){
    int pf = 0;
    for (int i=0;i<n;i++){
      pf += A[i][j];
      dp[i][j] = pf;
      if (i-1 >= 0 && j-1 >= 0) {
        dp[i][j] += dp[i-1][j-1];
      }
    }
  }
  while (q--){
    int i,j;
    cin >> i >> j;
    --i,--j;
    cout << dp[i][j] << "\n";
  }
}
