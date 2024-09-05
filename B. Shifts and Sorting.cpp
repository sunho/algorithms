#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  int cnt = 0;
  int last = -1;
  ll ans = 0;
  for (int i=0;i<n;i++){
    if (s[i] == '1') {
      cnt++; 
    } else {
      if (cnt != 0)
        ans += (cnt + 1);
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
