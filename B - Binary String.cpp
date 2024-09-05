#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cvt(string s) {
  ll m = 0;
  for (int i=0;i<(int)s.size();i++){
    m |= (ll)(s[i] == '1') << (s.size()-1-i);
  }
  return m;
}

void solve() {
  ll k;
  cin >> k;
  string s;
  cin >> s;
  int ans = 0;
  while (cvt(s) > k) {
    int found = (int)s.size()-1;
    for (int i=1;i<(int)s.size();i++) {
      if (s[i] == '1') {
        found = i;
        break;
      }
    }
    s.erase(s.begin()+found);
    ans++;
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
