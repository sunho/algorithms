#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#else
#define dbg(x...) 
#endif


array<int,2> dirs[] = {{-1,0},{0,1},{1,0},{0,-1}};

void solve() {
  int n,m;
  cin >> n >> m;
  int x,y,d;
  cin >> x >> y >> d;
  vector vis(n, vector(m, array<array<char,4>,2>{}));
  vector vis2(n, vector(m, false));
  array<int,2> cur = {x,y};
  int dir = d;
  vector<vector<int>> A(n, vector<int>(m));
  vector<vector<int>> B(n, vector<int>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      char c;
      cin >> c;
      A[i][j] = c-'0';
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      char c;
      cin >> c;
      B[i][j] = c-'0';
    }
  }
  int last_rm = 0;
  int ans = 0;
  while (cur[0] >= 0 && cur[0] < n && cur[1] >= 0 && cur[1] < m) {
    ans ++;
    int x = cur[0], y = cur[1];
    if (vis[x][y][vis2[x][y]][dir]) {
      break;
    }
    vis[x][y][vis2[x][y]][dir] = true;
    if (vis2[x][y]) {
      dir = (dir + B[x][y]) % 4;
    } else {
      dir = (dir + A[x][y]) % 4;
      last_rm = ans;
    }
    dbg(x,y,dir)
    vis2[x][y] = true;
    cur[0] += dirs[dir][0];
    cur[1] += dirs[dir][1];
  }
  cout << last_rm << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
