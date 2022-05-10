#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,a,b;
  cin >> n >> a >> b;
  if (a + b > n+1 || (a == n && b != 1)) {
    cout << -1 << "\n";
    return;
  }
  if (a == n && b == 1) {
    for(int i=1;i<=n;i++) cout << i << " ";
    cout << "\n";
    return;
  }
  int rs = b-2;
  int r = n - rs - a;
  if (rs < 0 || r > a) {
    cout << -1 << "\n";
    return;
  }
  for (int i = n-a+1; i <= n; i++) {
    cout << i << " ";
  }
  for (int i = n-a; i >= n-rs-a+1; i--) {
    cout << i << " ";
  }
  for (int i=1;i<=r;i++){
    cout << i << " ";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
