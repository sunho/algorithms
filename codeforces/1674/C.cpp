#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  string s,t;
  cin >> s >> t;
  if (t == "a") {
    cout << 1 << "\n";
    return;
  }
  bool a_e = false;
  for(char c : t) {
    if (c == 'a') {
      a_e= true;
    }
  }
  if (a_e) {
    cout << -1 << "\n";
    return;
  }
  ll n = (ll)s.size();
  cout << (1ll << n) << "\n";
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
