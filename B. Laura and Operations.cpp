#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  vector<int> a(3);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  auto check = [&](int a, int b, int c) {
    if (b < c)
      swap(b, c);
    return (b - c) % 2 == 0;
  };
  cout << check(a[0], a[1], a[2]) << " " << check(a[1], a[0], a[2]) << " "
       << check(a[2], a[0], a[1]) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
