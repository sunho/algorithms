#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  int cur = 0;
  int ans = 0;
  while (cur < (int)t.size()) {
    int mx = 0;
    for (int i=0;i<(int)s.size();i++){
      int ptr = 0;
      while (i + ptr < (int)s.size() && cur + ptr < (int)t.size() && t[cur+ptr] == s[i+ptr]) {
        ptr++;
      }
      mx = max(mx, ptr);
    }
    cur += mx;
    ans++;
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
