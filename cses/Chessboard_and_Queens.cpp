#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  vector M(8, vector(8, ' '));
  for (int i=0;i<8;i++){
    for (int j=0;j<8;j++){
      cin >> M[i][j];
    }
  }
  int ans = 0;
  vector<pair<int,int>> queens;
  auto dfs = [&](int ii, int jj, auto&& self) -> void {
    if (queens.size() == 8) {
      ans ++;
      return;
    }
    for (int i=ii;i<8;i++){
      for (int j=0;j<8;j++){
        if (i == ii && j < jj) {
          continue;
        }
        if (M[i][j] == '*')
          continue;
        bool ok = true;
        for (auto [x,y] : queens) {
          if (x == i || y == j || x-y == i-j || x+y == i+j) {
            ok = false;
          }
        }
        if (ok) {
          queens.push_back({i,j});
          self(i,j,self);
          queens.pop_back();
        }
      }
    }
  };
  dfs(0,0,dfs);
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
