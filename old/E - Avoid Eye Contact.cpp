#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<char>> M(n, vector<char>(m));
  pair<int,int> s,t;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
      if (M[i][j] == 'S') {
        s = {i,j};
        M[i][j] = '.';
      }
      if (M[i][j] == 'G') {
        t = {i,j};
        M[i][j] = '.';
      }
    }
  }
  vector<vector<char>> M2 = M;
  auto is_valid = [&](pair<int,int> p) {
    auto [x,y] = p;
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  auto dfs = [&](pair<int,int> start, pair<int,int> dir, char tile) {
    bool tog = false;
    while (is_valid(start)) {
      auto [i,j] = start;
      if (M[i][j] != '.') {
        if (M[i][j] == tile) {
          tog = true;
        } else {
          tog = false;
        }
      } else {
        if (tog) {
          M2[i][j] = '#';
        }
      }
      start.first += dir.first;
      start.second += dir.second;
    }
  };
  for (int i=0;i<n;i++){
    dfs({i,0}, {0,1}, '>');
    dfs({i,m-1}, {0,-1}, '<');
  }
  for (int i=0;i<m;i++){
    dfs({0,i}, {1,0}, 'v');
    dfs({n-1,i}, {-1,0}, '^');
  }
  queue<pair<int,int>> q;
  q.push(s);
  vector<vector<int>> dist(n, vector<int>(m,-1));
  dist[s.first][s.second] = 0;
  while (!q.empty()) {
    auto [x,y] = q.front();
    q.pop();
    pair<int,int> cands[] = {{x,y+1},{x,y-1},{x+1,y},{x-1,y}};
    for (auto [u,v] : cands) {
      if (!is_valid({u,v})) continue;
      if (M2[u][v] != '.') continue;
      if (dist[u][v] != -1) continue;
      dist[u][v] = dist[x][y]+1;
      q.push({u,v});
    }
  }
  cout << dist[t.first][t.second];
}
