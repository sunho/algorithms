#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> A(n, vector<char>(m));
  pair<int, int> r, b, t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
      if (A[i][j] == 'R') {
        r = {i, j};
      } else if (A[i][j] == 'B') {
        b = {i, j};
      } else if (A[i][j] == 'O') {
        t = {i, j};
      }
    }
  }
  int dist[10][10][10][10];
  memset(dist, -1, sizeof(dist));
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push({r, b});
  dist[r.first][r.second][b.first][b.second] = 0;
  auto push = [&](pair<int, int> cur, pair<int, int> other, int dx, int dy) {
    if (cur == t) {
      return cur;
    }
    while (true) {
      auto nxt = cur;
      nxt.first += dx;
      nxt.second += dy;
      if (A[nxt.first][nxt.second] == '#') {
        break;
      }
      if (A[nxt.first][nxt.second] == 'O') {
        cur = nxt;
        break;
      }
      if (nxt == other)
        break;
      cur = nxt;
    }
    return cur;
  };
  while (!q.empty()) {
    auto [ur, ub] = q.front();
    q.pop();
    pair<int, int> dirs[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for (auto [dx, dy] : dirs) {
      auto vr = push(ur, ub, dx, dy);
      auto vb = push(ub, vr, dx, dy);
      vr = push(vr, vb, dx, dy);
      vb = push(vb, vr, dx, dy);
      if (dist[vr.first][vr.second][vb.first][vb.second] == -1) {
        dist[vr.first][vr.second][vb.first][vb.second] =
            dist[ur.first][ur.second][ub.first][ub.second] + 1;
        if (vr != t && vb != t) {
          q.push({vr, vb});
        }
      }
    }
  }
  const int inf = 1e9;
  int ans = inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == t.first && j == t.second)
        continue;
      if (dist[t.first][t.second][i][j] != -1) {
        ans = min(ans, dist[t.first][t.second][i][j]);
      }
    }
  }
  if (ans <= 10) {
    cout << ans << "\n";
  } else {
    cout << -1 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
