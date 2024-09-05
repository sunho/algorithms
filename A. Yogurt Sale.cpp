#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 1e9;
  for (int i=0;i<=n;i++){
    if (n-2*i < 0) break;
    ans = min(ans,(n - 2*i) * a + b*i);
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
