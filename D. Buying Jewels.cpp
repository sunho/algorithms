#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;
  if (n == k) {
    cout << "YES" << "\n";
    cout << 1 << "\n";
    cout << 1 << "\n";
    return;
  }
  if (k > n || n < 2*k-1) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  cout << 2 << "\n";
  cout << n-k+1 << " " << 1 << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
