#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    if (t.size() == 3) {
      if (s.empty()) {
        s = t;
      }
      s = min(s, t);
    }
  }
  cout << s << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
