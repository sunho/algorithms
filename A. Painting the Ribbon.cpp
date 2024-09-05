#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  if (n - (n+m-1)/m <= k) {
    cout << "NO"  << "\n";
  } else {
    cout << "YES" << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
