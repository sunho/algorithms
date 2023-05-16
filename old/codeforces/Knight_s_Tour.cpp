#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int px[] = {1,1,2,2,-1,-1,-2,-2};
int py[] = {2,-2,1,-1,2,-2,1,-1};

int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);

  array<array<bool, 8>, 8> vis{};
  array<array<int, 8>, 8> ans{};
  auto is_valid = [&](int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8 && !vis[x][y];
  };
  auto get_deg = [&](int x, int y) { 
    int res = 0;
    for (int i=0;i<8;i++){
      int xx = x + px[i], yy = y + py[i];
      if (is_valid(xx,yy)) res++;
    }
    return res;
  };

  int s,t;
  cin >> t >> s;
  --s,--t;
  auto dfs = [&](auto self, int x, int y, int cur) -> void {
    vis[x][y] = true;
    ans[x][y] = cur;
    if (cur == 64) {
      for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
          cout << ans[i][j] << " ";
        }
        cout << "\n";
      }
      exit(0);
    }
    array<tuple<int,int,int>,8> cands{};
    for (int i=0;i<8;i++) {
      int x2 = x+px[i], y2 = y+py[i];
      if (is_valid(x2,y2)) {
        cands[i] = {get_deg(x2,y2), x2,y2};
      } else {
        cands[i] = {8,0,0};
      }
    }
    sort(begin(cands), end(cands));
    for (auto [deg, xx, yy] : cands){
      if (deg != 8) {
        self(self, xx, yy, cur+1);
      }
    }
    vis[x][y] = false;
  };
  dfs(dfs, s, t, 1);
  
}
