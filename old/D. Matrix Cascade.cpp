#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> M(n, vector<int>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      char c;
      cin >> c;
      M[i][j] = c == '1';
    }
  }
  vector<int> diag(2*n-1), vdiag(2*n-1);
  vector<int> row(n);
  int ans = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      int diag_id = i + j;
      int vdiag_id = i - j + n - 1;
      row[j] += diag[diag_id];
      row[j] += vdiag[vdiag_id];
      int cnt = M[i][j] ^ (row[j] % 2);
      ans += cnt;
      row[j] += cnt;
      diag[diag_id] += cnt;
      vdiag[vdiag_id] += cnt;
    }
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
