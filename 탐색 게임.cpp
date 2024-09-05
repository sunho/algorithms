#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n = 100;
  vector<vector<int>> A(n, vector<int>(n));
  int cnt = 1;
  for (int i=0;i<n-2;i++){
    for (int j=0;j<n;j++){
      if (i%2 == 0) {
        if (i == (j) && i != n-1) continue;
        A[i][n-j-1] = cnt++;
      } else {
        if (i == (n-j-1) && i != n-1) continue;
        A[i][j] = cnt++;
      }
    }
  }
  for (int j=n-1;j>=0;j--){
    if (j >= 3) {
      A[n-2][j] = cnt++;
    }
  }
  A[n-2][0] = cnt++;
  A[n-2][2] = cnt++;
  for (int j=2;j<n;j++){
    A[n-1][j] = cnt++;
  }
  A[n-1][1] = cnt++;
  A[n-1][0] = cnt++;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (A[i][j] == 0) {
        A[i][j] = cnt++;
      }
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
