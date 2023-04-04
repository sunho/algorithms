#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector M(n, vector(m, ' '));
  auto get_dir = [](char c) -> pair<int,int> {
    switch(c) {
      case 'R': return {0,1};
      case 'L': return {0,-1};
      case 'D': return {1,0};
      case 'U': return {-1,0};
    }
    return {-1,-1};
  };
  int inf = 1e9;
  auto bfs = [&](vector<pair<int,int>> s, vector<vector<char>>& p) -> vector<vector<int>> {
    vector dist(n, vector(m, inf));
    queue<pair<int,int>> q;
    for (auto t : s) {
      dist[t.first][t.second] = 0;
      q.push(t);
    }
    while(!q.empty()) {
      auto [i,j] = q.front();
      q.pop();
      char cands[] = {'U','D','L','R'};
      for (char c : cands) {
        auto [dx, dy] = get_dir(c);
        int x = i + dx, y = j + dy;
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (M[x][y] == '#') continue;
        if (dist[x][y] == inf) {
          p[x][y] = c;
          dist[x][y] = dist[i][j] + 1;
          q.push({x,y});
        }
      }
    }
    return dist;
  };
  vector<pair<int,int>> monsters;
  vector p(n, vector(m, ' '));
  pair<int,int> ch;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
      if (M[i][j] == 'A') {
        ch = {i,j};
      }
      if (M[i][j] == 'M') {
        monsters.push_back({i,j});
      }
    }
  }
  auto m_dist = bfs(monsters, p);
  auto char_dist = bfs({ch}, p);
  pair<int,int> escape = {-1,-1};
  for (int i=0;i<n;i++){
    pair<int,int> cands[] = {{i,0}, {0,i}, {n-1,i}, {i,m-1}};
    for (auto [j, k] : cands) {
      if ((M[j][k] == '.' || M[j][k] == 'A') && char_dist[j][k] < m_dist[j][k]) {
        escape = {j, k};
      }
    }
  }

  if (escape.first == -1) {
    cout << "NO" << "\n";
    return;
  }
  vector<int> path;
  pair<int,int> cur = escape;
  while (cur != ch) {
    auto [i,j] = cur;
    path.push_back(p[i][j]);
    auto [dx,dy] = get_dir(p[i][j]);
    cur = {i-dx,j-dy};
  }
  reverse(begin(path), end(path));
  cout << "YES" << "\n";
  cout << path.size() << "\n"; 
  for (char c : path) {
    cout << c;
  }
 }

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
