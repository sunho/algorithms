#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<char>> A(n, vector<char>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> A[i][j];
    }
  }
  const int inf = 1e9;
  long long mn = 0, mx = 0;
  for (int i=0;i<n;i++){
    vector<int> dp(m+1);
    vector<int> dp2(m+1);
    int sum = 0;
    for (int j=0;j<m;j++){
      sum += A[i][j] == '1';
    }
    for (int j=0;j<m;j++){
      if (j + 1 < m) {
        if (A[i][j] == '1' && A[i][j+1] == '1') {
          dp[j+2] = max(dp[j+2],dp[j]+1);
        }
      }
      dp[j+1] = max(dp[j+1],dp[j]);
    }
    for (int j=0;j<m;j++){
      if (j + 1 < m) {
        if (A[i][j] != '1' || A[i][j+1] != '1') {
          dp2[j+2] = max(dp2[j+2],dp2[j]+1);
        }
      }
      dp2[j+1] = max(dp2[j+1],dp2[j]);
    }
    mn += sum - min(dp[m],m/4);
    mx += sum - (m/4-min(dp2[m],m/4));
  }
  cout << mn << " " << mx << "\n";
}
