#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(x) "(" << #x <<": " << (x) << ") "
template<typename Ostream, typename Cont>
enable_if_t<is_same_v<Ostream,ostream>, Ostream&> 
operator<<(Ostream& os, const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<int>> walls(n, vector<int>(m));
  int empty = n*m;
  for (int i=0;i<k;i++){
    int y,x;
    cin >> y >> x;
    --x,--y;
    walls[y][x] = true;
    empty--;
  }
  vector<vector<ll>> pf(n+1, vector<ll>(m+1));
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++){
      pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + walls[i-1][j-1];
    }
  }

  auto query = [&](int i2, int j2, int i, int j) {
    return pf[i+1][j+1] - pf[i+1][j2] - pf[i2][j+1] + pf[i2][j2];
  };

  auto check = [&](int h) {
    vector<vector<int>> vis(n, vector<int>(m));
    int cnt = 0;

    auto dfs = [&](auto self, int i, int j) -> void {
      vis[i][j] = true;
      assert(!query(i,j,i+h-1,j+h-1));
      pair<int,int> cands[] = {{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
      for (auto [x,y] : cands) {
        if (x < 0 || x > n-h || y < 0 || y > m-h) continue;
        if (query(x,y,x+h-1,y+h-1)) continue;
        if (vis[x][y]) continue;
        self(self,x,y);
      }
    };

    for (int i=0;i<=n-h;i++) {
      for (int j=0;j<=m-h;j++){
        if (!query(i,j,i+h-1,j+h-1) && !vis[i][j]) {
          if (cnt) return false;
          cnt++;
          dfs(dfs, i, j);
        }
      }
    }

    vector<vector<ll>> pf2(n+1, vector<ll>(m+1));
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++){
        pf2[i][j] = pf2[i-1][j] + pf2[i][j-1] - pf2[i-1][j-1] + vis[i-1][j-1];
      }
    }
    auto query2 = [&](int i2, int j2, int i, int j) {
      return pf2[i+1][j+1] - pf2[i+1][j2] - pf2[i2][j+1] + pf2[i2][j2];
    };

    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++){
        if (!walls[i][j] && !query2(max(i-h+1,0),max(j-h+1,0),i,j)) {
          return false;
        }
      }
    }

    return cnt == 1;
  };

  int ok = 0, ng = min(n,m) + 1;
  while (ng - ok > 1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  if (ok == 0) {
    cout << -1 << "\n";
  } else {
    cout << ok << "\n";
  }
}
