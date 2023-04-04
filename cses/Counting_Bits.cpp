#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(int n) {
  if (n == 1) return 1;
  return 2*f(n-1) + (1LL << (n-1));
}

void solve() {
  ll x;
  cin >> x;
  ll ans = 0;
  bool first = false;
  int bits = 0;
  for (int i=62;i>=0;i--){
    if (x & (1LL << i)) {
      bits++;
      if (!first) {
        first = true;
        ans = f(i+1);
      }
    } else {
      if (first) {
        ans -= (bits+1)*(1LL << i);
        if (i != 0)
          ans -= f(i);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
