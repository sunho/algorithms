#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> area(n, vector<int>(m));
  vector<vector<char>> A(n, vector<char>(m));
  vector<vector<char>> B(n, vector<char>(m));
  int id = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  auto dfs = [&](auto &&self, int i, int j) -> void {
    area[i][j] = id;
    pair<int, int> cands[] = {{i - 1, j}, {i + 1, j}, {i, j + 1}, {i, j - 1}};
    for (auto [u, v] : cands) {
      if (u < 0 || u >= n || v < 0 || v >= m)
        continue;
      if (A[i][j] != A[u][v])
        continue;
      if (area[u][v])
        continue;
      self(self, u, v);
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!area[i][j]) {
        dfs(dfs, i, j);
        id++;
      }
    }
  }
  map<int, char> vis;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> B[i][j];
      if (vis.count(area[i][j])) {
        if (vis[area[i][j]] != B[i][j]) {
          cout << "NO"
               << "\n";
          return;
        }
      } else {
        vis[area[i][j]] = B[i][j];
      }
    }
  }
  cout << "YES";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
