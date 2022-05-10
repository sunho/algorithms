#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  vector<vector<int>> A(4, vector<int>(4));
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cin >> A[i][j];
    }
  }

  int ans = 0;
  vector<vector<int>> B(4, vector<int>(4));
  auto check = [&]() {
    int cnt = 0;
    vector<vector<bool>> vis(4, vector<bool>(4));
    auto dfs = [&](int i, int j, auto&& self) {
      if (vis[i][j]) return;
      vis[i][j] = true;
      array<pair<int,int>,4> cands = {{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}};
      for (auto cand : cands) {
        if (cand.first < 0 || cand.first >= 4 || cand.second < 0 || cand.second >= 4) continue;
        if (B[cand.first][cand.second] == 0) continue;
        self(cand.first, cand.second, self);
      }
    };
    auto dfs2 = [&](int i, int j, auto&& self) {
      if (vis[i][j]) return false;
      vis[i][j] = true;
      array<pair<int,int>,4> cands = {{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}};
      bool res = false;
      for (auto cand : cands) {
        if (cand.first < 0 || cand.first >= 4 || cand.second < 0 || cand.second >= 4) {
          res = true;
          continue;
        }
        if (B[cand.first][cand.second] == 1) continue;
        res |= self(cand.first, cand.second, self);
      }
      return res;
    };
    for (int i=0;i<4;i++){
      for (int j=0;j<4;j++){
        if (A[i][j] == 1 && B[i][j] == 0) return false;
        if (!vis[i][j] && B[i][j] == 1) {
          cnt++;
          dfs(i,j,dfs);
        }
        if (!vis[i][j] && B[i][j] == 0) {
          if (!dfs2(i,j,dfs2)) {
            return false;
          }
        }
      }
    }
    return cnt == 1;
  };
  auto go = [&](int i, int j, auto&& self) {
    if (i == 4) {
      if (check()) {
        ans++;
      }
      return;
    }
    if (j == 4) {
      self(i+1,0,self);
      return;
    }
    for(int a : {0,1}) {
      B[i][j] = a;
      self(i,j+1,self);
    }
  };
  go(0,0,go);
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
