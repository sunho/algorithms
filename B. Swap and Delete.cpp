#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int zero = 0, one = 0;
  for (int i=0;i<s.size();i++){
    if (s[i] == '0') {
      zero++;
    } else {
      one++;
    }
  }
  for (int i=0;i<s.size();i++){
    if (s[i] == '1') {
      if (zero > 0) {
        zero --;
      } else {
        cout << s.size() - i << "\n";
        return;
      }
    } else {
      if (one > 0) {
        one --;
      } else {
        cout << s.size() - i << "\n";
        return;
      }
    }
  }
  cout << 0 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
