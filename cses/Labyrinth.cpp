#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector M(n, vector(m, ' '));
  pair<int,int> s;
  for (int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> M[i][j];
      if (M[i][j] == 'A') {
        s = {i,j};
      }
    }
  }
  const int inf = 1e9;
  vector dist(n, vector(m, inf));
  vector prd(n, vector(m, ' '));
  dist[s.first][s.second] = 0;
  queue<pair<int,int>> q;
  q.push(s);
  auto to_dir = [](char c) -> pair<int,int> {
    switch (c) {
      case 'U': return make_pair(-1,0);
      case 'D': return make_pair(1, 0);
      case 'L': return make_pair(0,-1);
      case 'R': return make_pair(0,1);
    }
    return make_pair(0,0);
  };

  while(!q.empty()) {
    auto [i,j] = q.front();
    q.pop();
    char cands[] = {'U','D','L','R'};
    for (char c : cands) {
      auto [di,dj] = to_dir(c);
      int x = i + di, y = j + dj;
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      if (dist[x][y] != inf) continue;
      if (M[x][y] == '#') continue;
      dist[x][y] = dist[i][j] + 1;
      prd[x][y] = c;
      q.push({x,y});
      if (M[x][y] == 'B') {
        cout << "YES" << "\n";
        cout << dist[x][y] << "\n";
        stack<char> stk;
        while (x != s.first || y != s.second) {
          stk.push(prd[x][y]);
          auto [dx, dy] = to_dir(prd[x][y]);
          x -= dx;
          y -= dy;
        }
        while (!stk.empty()) {
          cout << stk.top();
          stk.pop();
        }
        cout << "\n";
        return;
      }
    }
  }
  cout << "NO" << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
