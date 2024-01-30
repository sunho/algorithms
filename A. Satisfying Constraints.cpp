#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  const int inf = 1e9;
  int mn = 1, mx = inf;
  int n;
  cin >> n;
  set<int> ban;
  for (int i=0;i<n;i++){
    int a,x;
    cin >> a >> x;
    if (a == 1) {
      mn = max(mn, x);
    } else if (a == 2) {
      mx = min(mx, x);
    } else {
      ban.insert(x);
    }
  }
  int ans = mx - mn + 1;
  if (mx < mn) {
    ans = 0;
  }
  for (int x : ban) {
    if (mn <= x && x <= mx) {
      ans--;
    }
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
