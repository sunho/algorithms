#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, 2 * ((n + i - 1) / i + i));
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
