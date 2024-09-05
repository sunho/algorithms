#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  if (k >= n-1) {
    cout << 1 << "\n";
  } else {
    cout << n << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
