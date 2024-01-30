#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int x,n;
  cin >> x >> n;
  int ans = 1;
  for (int i=1;i*i<=x;i++) {
    if (x % i == 0) {
      if (x/i >= n) {
        ans = max(ans,i);
      }
      int d = x/i;
      if (x/d >= n) {
        ans = max(ans,d);
      }
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
