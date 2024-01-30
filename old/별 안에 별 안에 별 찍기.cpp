#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int m = 1;
  for (int i = 0; i < n; i++)
    m *= 5;
  vector<vector<char>> ans(m, vector<char>(m, ' '));
  vector<string> M = {"..*..", "..*..", "*****", ".***.", ".*.*."};
  auto f = [&](auto &&self, int i, int j, int sz) -> void {
    if (sz == 1) {
      ans[i][j] = '*';
      return;
    }
    int nxt = sz / 5;
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        if (M[x][y] == '*') {
          self(self, i + x * nxt, j + y * nxt, nxt);
        }
      }
    }
  };
  f(f, 0, 0, m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
