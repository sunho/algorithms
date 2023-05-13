#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  int ans = 1e9;
  for (char c = 'a'; c <= 'z'; c++) {
    int cnt = 0;
    string ss = s;
    while (true) {
      bool ok = true;
      for (int i=0;i<ss.size();i++){
        if (ss[i] != c) {
          ok = false;
        }
      }
      if (ok) {
        ans = min(ans, cnt);
        break;
      }
      cnt++;
      string nxt;
      bool last = false;
      for (int i=0;i<ss.size();i++){
        if (!last) {
          if (ss[i] != c) {
            last = true;
          } else {
            nxt.push_back(ss[i]);
          }
        } else {
          nxt.push_back(ss[i]);
          last = false;
        }
      }
      ss = nxt;
      if (ss.empty())
        break;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
