#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(4)));
    int x = i, y = 0, k = 0;
    bool ok = true;
    while (x >= 0 && x < n && y >= 0 && y < m) {
      if (vis[x][y][k]) {
        ok = false;
        break;
      }
      vis[x][y][k] = true;
      auto [dx, dy] = delta[k];
      int a = A[x][y];
      x += dx * a;
      y += dy * a;
      k++;
      k %= 4;
    }
    if (!ok) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << "\n";
  for (int a : ans) {
    cout << a + 1 << " ";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
