#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using ld = long double;

void solve() {
  int a,b;
  cin >> a >> b;
  pair<ld,ld> v = {a,b};
  ld norm = sqrtl(v.first*v.first + v.second*v.second);
  v.first /= norm, v.second /= norm;
  cout << fixed << setprecision(10) << v.first << " " << v.second << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
