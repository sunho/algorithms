#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll x, y;
  cin >> x >> y;
  if (x == 1) {
    cout << y*y << "\n";
    return;
  }
  if (y % x == 0) {
    cout << y*y/x << "\n";
  } else {
    cout << lcm(x,y) << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
  solve();
}
