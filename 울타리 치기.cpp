#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  vector<int> table = {0,1,2,3,4,5,7,8,10,12,14,16};
  int n;
  cin >> n;
  if (n <= 11) {
    cout << table[n] << "\n";
  } else {
    ll ans = n+7;
    n -= 12;
    ll k = 12;
    ll cell_adj = 1;
    ll rem = k;
    while (n) {
      n--;
      if (rem == cell_adj+1) {
        k += 6;
        rem = k;
        ans += cell_adj+1;
        continue;
      }
      if (rem == k) {
        rem -= cell_adj;
        ans += cell_adj;
        cell_adj++;
      } else {
        rem -= cell_adj;
        ans += cell_adj;
      }
    }
    cout << ans << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
