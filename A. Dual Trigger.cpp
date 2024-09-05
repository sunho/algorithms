#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i=0;i<n;i++){
    if (s[i] == '1') {
      cnt++;
    }
  }
  if (cnt == 2) {
    for (int i=0;i<n-1;i++){
      if (s[i] == '1' && s[i+1] == '1') {
        cout << "NO" << "\n";
        return;
      }
    }
    cout << "YES" << "\n";
  } else {
    if (cnt % 2 == 0) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
