#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int x,y;
  cin >> x >> y;
  if (y < x) {
    cout << "0 0" << "\n";
    return;
  }
  if (y % x != 0) {
    cout << "0 0" << "\n";
    return;
  }
  if (x == y) {
    cout << "1 1" << "\n";
    return;
  }
  int c = y/x;
  for(int b = 2; b <= 100; b++) {
    int cc = c;
    int a = 0;
    bool ok = true;
    while (cc != 1) {
      if (cc%b != 0) {
        ok = false;
        break;
      }
      cc /= b;
      a++;
    }
    if (ok) {
      cout << a << " " << b << "\n";
      return;
    }
  }
  cout << "0 0" << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
