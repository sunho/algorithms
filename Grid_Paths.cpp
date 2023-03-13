#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  vector<string> path;
  string cand;
  vector vis(7, vector(7, false));
  auto dfs = [&](int i, int j, auto&& self) -> void {
    vis[i][j] = true;
    if (path.size() == 48 && i == 6 && j == 6) {
      path.push_back(cand);
    } else {
      vector<tuple<int,int, char>> cands = {{i+1,j, 'U'},{i-1,j,'D'},{i,j+1,'R'},{i,j-1,'L'}};
      for (auto [x,y,c] : cands) {
        if (x < 0 || x >= 7 || y < 0 || y >= 7) continue;
        if (vis[x][y]) continue;
        cand.push_back(c);
        self(x,y,self);
        cand.pop_back();
      }
    }
    vis[i][j] = false;
  };
  dfs(0,0,dfs);

}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
