#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#define dbg(...) std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

void solve() {
  int n,c,d;
  cin >> n >> c >> d;
  vector<int> A(n*n);
  for (int i=0;i<n*n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  vector<vector<int>> B(n, vector<int>(n, -1));
  B[0][0] = A[0];
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (j+1 < n) {
        if (B[i][j+1] == B[i][j] + c || B[i][j+1] == -1) {
          B[i][j+1] = B[i][j] + c;
        } else {
          cout << "NO" << "\n";
          return;
        }
      }
      if (i+1 < n) {
        if (B[i+1][j] == B[i][j] + d || B[i+1][j] == -1) {
          B[i+1][j] = B[i][j] + d;
        } else {
          cout << "NO" << "\n";
          return;
        }
      }
    }
  }
  dbg(B);
  vector<int> A2;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      A2.push_back(B[i][j]);
    }
  }
  sort(begin(A2),end(A2));
  if (A2 == A) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
