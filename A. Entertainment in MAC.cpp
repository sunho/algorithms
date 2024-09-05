#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  string t;
  t = s;
  reverse(begin(t),end(t));
  if (n % 2 == 0) {
    if (s <= t) {
      cout << s << "\n";
    } else {
      cout << t << s << "\n";
    }
  } else {
    if (t <= s) {
      cout << t << "\n";
    } else {
      cout << s << t << "\n";
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
