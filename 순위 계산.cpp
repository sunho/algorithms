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
  int r;
  cin >> r;
  int n;
  cin >> n;
  vector<int> A(n);
  int mn = r, mx = r;
  int y = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    if (A[i] <= mx) {
      mx++;
    }
    if (mn > A[i]) {
      mn ++;
    } else if (mn == A[i]) {
      y++;
    } else if (A[i] <= mn + y){
      y = mn+y-A[i]+1;
      mn = A[i];
    }
    dbg(A[i], mn, y);
  }
  cout << mn << " " << mx << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
