#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  string s;
  cin >> s;
  auto check = [](string t) {
    string k = t;
    reverse(all(k));
    return t == k;
  };
  int ans = 1e9;
  for(int i=0;i<(int)s.size();i++){
    string k = s;
    auto a = s.substr(0,i);
    reverse(all(a));
    k += a;
    if (check(k)) {
      ckmin(ans, (int)k.size());
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
