#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  const int inf = 1e9;
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++){
      cin >> A[i];
      --A[i];
    }
    vector<vector<int>> dp(n+1,vector(n+1,n));
    for (int i=0;i<=n;i++){
      dp[i][0] = 0;
      for (int j=1;j<=n;j++){
        if (j == 1 || A[j-2] < A[j-1]){
          dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
        if (i >= 1) {
          for (int k=0;k<j;k++){
            if (k == 0 || A[k-1] < A[j-1]) {
              dp[i][j] = min(dp[i][j], dp[i-1][k] + j-k-1);
            }
          }
        }
      }
    }
    for (int i=1;i<=n;i++){
      int ans = n-1;
      for (int j=0;j<=n;j++){
        ans = min(ans, dp[i-1][j]+n-j);
        ans = min(ans, dp[i][n]);
      }
      cout << ans << " ";
    }
    cout << "\n";
  }

}
