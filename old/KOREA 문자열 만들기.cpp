#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int ptr = 0;
  string t = "KOREA";
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[ptr]) {
      ptr++;
      ans++;
    }
    if (ptr == t.size()) {
      ptr = 0;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
