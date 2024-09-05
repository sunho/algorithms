#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> A(m);
  for (int i=0;i<m;i++){
    cin >> A[i];
  }
  for (int i=0;i<m;i++){
    A.push_back(A[i]+n);
  }
  A.push_back(2*n+A[0]);
  auto check = [&](int lim) {
    for (int i=0;i<m;i++){
      int cnt = 0;
      int st = A[i];
      for (int j=i;j<i+m+1;j++){
        if (A[j] - st >= lim) {
          cnt ++;
          st = A[j];
        }
      }
      if (cnt >= k) {
        return true;
      }
    }
    return false;
  };
  int ok = 0, ng = n+1;
  while (ng-ok>1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  if (ok == 0) {
    cout << -1 << "\n";
    return;
  }
  cout << ok << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
