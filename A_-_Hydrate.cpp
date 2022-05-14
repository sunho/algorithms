#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  // A = a + bx
  // B = c*x
  // A <= D*B
  // a+bx <= D*c*x
  // bx - D*c*x <= -a
  // -(b-D*c)*x > a
  // x > ceil(a / (-(b-D*c)))
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  const int inf = 1e5+1;
  int ng = -1, ok = inf;
  while (ok-ng > 1) {
    int mid = (ng+ok)/2;
    if (a+(ll)b*mid <= (ll)d*c*mid) ok = mid;
    else ng = mid;
  }
  if (ok == inf || ok == -1) {
    cout << -1 << "\n";
    return;
  }
  cout << ok << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
