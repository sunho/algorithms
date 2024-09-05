#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;
  auto get_mx = [](ll x) {
    auto s = to_string(x);
    int n = (int)s.size();
    string ss(n, '0');
    bool lowered = false;
    for (int i=0;i<(n+1)/2;i++){
      if (lowered) {
        ss[i] = ss[n-i-1] = '9';
      } else {
        ss[i] = ss[n-i-1] = s[i];
        if (stoll(ss) > x) {
          if (i == 0 && s[i] == '1') {
            ss[0] = '0';
            for (int j=1;j<n;j++) {
              ss[j] = '9';
            }
            return stoll(ss);
          }
          ss[i] = ss[n-i-1] = s[i]-1;
          lowered = true;
        }
      }
    }
    return stoll(ss);
  };
  vector<ll> ans;
  while (n) {
    ll x = get_mx(n);
    ans.push_back(x);
    n -= x;
  }
  cout << ans.size() << "\n";
  for (ll x : ans) {
    cout << x << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
