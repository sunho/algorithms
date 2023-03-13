#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  vector<int> hsum(3);
  vector<int> vsum(3);
  for(int i=0;i<3;i++) cin >> hsum[i];
  for(int i=0;i<3;i++) cin >> vsum[i];
  vector<vector<int>> grid(3, vector<int>(3));
  int ans = 0;
  auto dfs = [&](int id, auto&& self) -> void {
    int i = id / 2;
    int j = id % 2;
    if (id == 4) {
      for (int j=0;j<2;j++){
        grid[2][j] = vsum[j] - grid[0][j] - grid[1][j];
        if (grid[2][j] < 1) return;
      }
      for (int j=0;j<3;j++){
        grid[j][2] = hsum[j] - grid[j][0] - grid[j][1];
        if (grid[j][2] < 1) return;
      }
      if (grid[2][2] != vsum[2] - grid[0][2] - grid[1][2])
        return;
      ans++;
      return;
    }
    for (int n=1;n<=28;n++){
      grid[i][j] = n;
      self(id+1, self);
    }
  };
  dfs(0, dfs);
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
