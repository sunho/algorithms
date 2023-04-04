#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int n=0;
  bool vis[7][7] = {};
  int cur = 0;
  set<string> visited;
  auto check = [&](tuple<int,int> p) -> bool {
    auto [x,y] = p;
    if (x < 0 || x >= 7 || y < 0 || y >= 7)
      return false;
    return !vis[x][y];
  };
  auto dfs = [&](int i, int j, auto&& self) {
    if (cur == 48) {
      if (i == 6 && j == 0)
        n++;
      return;
    }
    if (i == 6 && j == 0)
      return;
    tuple<int,int> cands[] = {{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
    char pp[4] = {'D','U','R','L'};
    bool pos[4] = {check(cands[0]),check(cands[1]),check(cands[2]),check(cands[3])};
    if (pos[0] && pos[1] && !pos[2] && !pos[3])
      return;
    if (!pos[0] && !pos[1] && pos[2] && pos[3])
      return;
    for (int k=0;k<4;k++) {
      if (!pos[k]) continue;
      if (s[cur] != '?' && s[cur] != pp[k]) continue;
      auto [x,y] = cands[k];
      vis[x][y] = true;
      cur++;
      self(x,y,self);
      cur--;
      vis[x][y] = false;
    }
  };
  vis[0][0] = true;
  dfs(0,0,dfs);
  cout << n << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
