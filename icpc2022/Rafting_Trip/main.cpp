#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  vector<vector<char>> M(n, vector<char>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
    }
  }
  
  vector adj(n, vector(m, vector<pair<int,int>>()));
  vector<vector<pair<int,int>>> prd(n, vector<pair<int,int>>(m));
  vector<vector<int>> color(n, vector<int>(m));
  vector<vector<pair<int,int>>> cycles;
  vector<vector<int>> cycle_id(n, vector(m, -1));
  vector<pair<int,int>> ends;
  auto dfs = [&](auto self, int i, int j) {
    color[i][j] = 2;
    int x,y;
    switch (M[i][j]) {
      case '#':
      case '.':
        color[i][j] = 1;
        return;
      case '<':
        x=i,y=j-1;
        break;
      case '>':
        x=i,y=j+1;
        break;
      case '^':
        x=i-1,y=j;
        break;
      case 'v':
        x=i+1,y=j;
        break;
    }
    if (x >= 0 && x < n && y >= 0 && y < m) {
      if (color[x][y]==2) {
        cycles.push_back({});
        for (pair<int,int> cur = {i,j}; cur != make_pair(x,y); cur = prd[cur.first][cur.second]) {
          cycle_id[cur.first][cur.second] = cycles.size();
          cycles.back().push_back(cur);
        }
        cycle_id[x][y] = cycles.size();
        cycles.back().push_back({x,y});
      } else if (color[x][y] == 0) {
        prd[x][y] = {i,j};
        self(self,x,y);
      }
      adj[x][y].push_back({i,j});
    } else {
      ends.push_back({i,j});
    }
    color[i][j] = 1;
  };
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (color[i][j] == 0 && M[i][j] != '#' && M[i][j] != '.') {
        dfs(dfs, i, j);
      }
    }
  }
  int ans = 0;
  map<pair<int,int>, int> cnt;
  auto add = [&](int i, int j, int d) {
    pair<int,int> cands[] = {{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
    for (auto [x, y] : cands) {
      if (x<0 || x>=n || y<0 || y>=m) continue;
      if (M[x][y] == '#') {
        cnt[{x,y}]+=d;
        if (cnt[{x,y}] == 0) {
          cnt.erase({x,y});
        }
      }
    }
  };
  auto count = [&](auto self, int i, int j, int id) -> void {
    add(i,j,1);
    ans = max(ans, (int)cnt.size());
    for (auto [x, y] : adj[i][j]) {
      if (cycle_id[x][y] == id) continue;
      self(self, x, y, id);
    }
    add(i,j,-1);
  };

  for (auto& cycle : cycles) {
    for (auto [i,j] : cycle) {
      add(i,j,1);
    }
    for (auto [i,j] : cycle) {
      count(count, i, j, cycle_id[i][j]);
    }
    cnt.clear();
  }

  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (M[i][j] == '.' || M[i][j] == '#') {
        for (auto [x,y] : adj[i][j]) {
          count(count, x, y, -2);
        }
      }
    }
  }

  for (auto [x,y] : ends) {
    count(count,x,y,-2);
  }

  cout << ans << "\n";
}
