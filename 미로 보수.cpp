#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> M(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> M[i][j];
    }
  }
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> vis(n, vector<int>(m));
  vector<vector<pair<int, int>>> P(n, vector<pair<int, int>>(m));
  auto to_dir = [](char c) -> pair<int, int> {
    if (c == 'L') {
      return {0, -1};
    } else if (c == 'R') {
      return {0, 1};
    } else if (c == 'U') {
      return {-1, 0};
    } else {
      return {1, 0};
    }
  };
  int ans = 0;
  auto dfs = [&](auto &&self, int i, int j) {
    auto [dx, dy] = to_dir(M[i][j]);
    int u = i + dx, v = j + dy;
    if (u < 0 || u >= n || v < 0 || v >= m) {
      return;
    }
    if (vis[u][v] == 2) {
      pair<int, int> cur = {i, j};
      int mn = A[u][v];
      while (cur != make_pair(u, v)) {
        mn = min(mn, A[cur.first][cur.second]);
        cur = P[cur.first][cur.second];
      }
      ans += mn;
      return;
    } else if (vis[u][v] == 1) {
      return;
    }
    vis[i][j] = 2;
    P[u][v] = {i, j};
    self(self, u, v);
    vis[i][j] = 1;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        dfs(dfs, i, j);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
