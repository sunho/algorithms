#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  string s, t;
  cin >> s >> t;
  bool ans = false;
  for (int k = 0; k <26; k++) {
    string ss;
    ss.resize(s.size());
    for (int i=0;i<(int)s.size();i++){
      ss[i] = (char)(((s[i] - 'a' + k) % 26) + 'a');
    }
    if (ss == t) {
      ans = true;
    }
  }
  if (ans) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
