#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  vector<int> vis(n);
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i; j < n - 1; j++) {
      if (!vis[j]) {
        if (s[j] == 'A' && s[j + 1] == 'B') {
          vis[j] = true;
          swap(s[j], s[j + 1]);
          ans++;
        } else {
          break;
        }
      } else {
        break;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
