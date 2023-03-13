#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  int tt = 5;
  int tt2 = 2;
  while (n/tt) {
    ans += min(n/tt,n/tt2);
    tt*=5;
    tt2*=2;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
