#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int h,w;
  cin >> h >> w;
  if (h > w) swap(h,w);
  if (h%2 == 0) {
    int a = h/2, b = 2*w;
    if (a > b) swap(a,b);
    if (a != h || b != w) {
      cout << "Yes" << "\n";
      return;
    }
  }
  if (w%2 == 0) {
    int a = w/2, b = 2*h;
    if (a > b) swap(a,b);
    if (a != h || b != w) {
      cout << "Yes" << "\n";
      return;
    }
  }
  cout << "No" <<" \n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
