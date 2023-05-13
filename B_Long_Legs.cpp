#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int x,y;
  cin >> x >> y;
  if (x > y) swap(x,y);
  ll ans = 1e18;
  for (int m = 1; m <= 1e6; m++){
    ans = min(ans, 1LL * m-1 + (x+m-1)/m + (y+m-1)/m);
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
