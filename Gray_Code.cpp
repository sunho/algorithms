#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int m = 1 << n;
  vector ans(m, string(n, ' '));
  int cur = m;
  for (int i=0;i<n;i++){
    cur >>= 1;
    bool c = false;
    bool hold = true;
    for (int j=0;j<m;j++) {
      if (j % cur == 0) {
        if (!hold) {
          c ^= 1;
          hold = true;
        } else {
          hold = false;
        }
      }
      ans[j][i] = c + '0';
    }
  }
  for (string& line : ans) {
    cout << line << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
