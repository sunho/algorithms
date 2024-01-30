#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      cnt++;
  }
  if (cnt < k) {
    int last = 0;
    for (int i = 0; i < n; i++) {
      if (cnt < k) {
        if (s[i] == 'A') {
          cnt++;
          last = i;
        }
      }
    }
    cout << 1 << "\n";
    cout << last + 1 << " " << 'B' << "\n";
  } else if (cnt > k) {
    int last = 0;
    for (int i = 0; i < n; i++) {
      if (cnt > k) {
        if (s[i] == 'B') {
          cnt--;
          last = i;
        }
      }
    }
    cout << 1 << "\n";
    cout << last + 1 << " " << 'A' << "\n";
  } else {
    cout << 0 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
