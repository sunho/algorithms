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

  // y = 2*a + 4*b
  // a+b = x
  // b=x-a
  // y = 2*a + 4*(x-a)
  // y - 4x = -2a
  // 2a = 4x-y
  // a = 2x-floor(y/2)
  // a >= 0
  // b >= 0
  if ((4*x - y) % 2 != 0) {
    cout << "No" << "\n";
    return;
  }
  int a = 2*x - y/2;
  int b = x - a;
  if (a < 0 || b < 0) {
    cout << "No" << "\n";
    return;
  }
  cout << "Yes" << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
