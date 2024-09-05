#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, l;
  cin >> n >> l;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(rbegin(A),rend(A));
  auto check = [&](int lim) {
    int rem = l;
    for (int i=0;i<lim;i++){
      if (A[i] < lim) {
        if (rem > 0 && A[i] == lim-1) {
          rem--;
        } else {
          return false;
        }
      }
    }
    return true;
  };
  int ok = -1, ng = n+1;
  while (ng-ok>1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
