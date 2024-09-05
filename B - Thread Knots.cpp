#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<array<int,2>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i][0] >> A[i][1];
  }
  sort(begin(A),end(A));
  const ll inf = 1e10;
  auto check = [&](ll lim) {
    ll cur = -inf;
    for (int i=0;i<n;i++){
      ll r = max(cur + lim, (ll)A[i][0]);
      if (r > A[i][0] + A[i][1]) {
        return false;
      }
      cur = r;
    }
    return true;
  };
  ll ok = -1, ng = inf+10;
  while (ng-ok>1){
    ll mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
