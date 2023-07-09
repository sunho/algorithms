#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  int r;
  cin >> r;
  unordered_map<int, vector<int>> row_ban, col_ban;
  for (int i=0;i<r;i++){
    int t,d,c;
    cin >> t >> d >> c;
    if (d == 1) {
      row_ban[t].push_back(c);
    } else {
      col_ban[t].push_back(c);
    }
  }
  n++,m++;
  const int T = 2*n*m+2*r;
  vector<vector<int>> dp(n, vector<int>(m));
  dp[0][0] = 1;
  for (int t=1;t<=T;t++){
    vector<int> rban(n, 0);
    vector<int> cban(m, 0);
    for (int c : row_ban[t]) rban[c] = 1;
    for (int c : col_ban[t]) cban[c] = 1;
    bool survive = false;
    for (int i=n-1;i>=0;i--){
      for (int j=m-1;j>=0;j--){
        if (i-1 >= 0) dp[i][j] |= dp[i-1][j];
        if (j-1 >= 0) dp[i][j] |= dp[i][j-1];
        if (rban[i] || cban[j]) dp[i][j] = false;
        if (dp[i][j]) survive = true;
      }
    }
    if (dp[n-1][m-1]) {
      cout << t << "\n";
      return;
    }
    if (!survive) {
      cout << -1 << "\n";
      return;
    }
  }
  assert(false);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
