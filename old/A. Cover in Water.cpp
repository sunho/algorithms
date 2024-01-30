#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int last = 0;
  bool done = false;
  int ones = 0;
  int twos = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') {
      last++;
    } else {
      if (last >= 3) {
        done = true;
      } else if (last == 2) {
        twos++;
      } else if (last == 1) {
        ones++;
      }
      last = 0;
    }
  }
  if (last >= 3) {
    done = true;
  } else if (last == 2) {
    twos++;
  } else if (last == 1) {
    ones++;
  }
  if (done) {
    cout << 2 << "\n";
  } else {
    cout << 2 * twos + ones << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
