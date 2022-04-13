#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> M(n, vector<int>(m));
  auto is_valid = [&](pair<int,int> v) {
    return v.x >= 0 && v.x < n && v.y >= 0 && v.y < m;
  };
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(2)));
  dp[0][0][0] = 0;
  dp[0][0][1] = 0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if (i==0 && j==0)continue;
      if (i != 0) {
        dp[i][j][1] = dp[i-1][j][0]+1;
      }
      if (j != 0) {
        dp[i][j][0] = dp[i][j-1][1]+1;
      }
    }
  }
  ll cur = n*m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      for(int k=0;k<2;k++) {
        cur += dp[i][j][k];
      }
    }
  }

  auto set_dp = [&](int i,int j, int k, ll val) {
    cur -= dp[i][j][k];
    dp[i][j][k] = val;
    cur += val;
  };

  auto update_dp = [&](int i, int j, int k) {
    if (k == 1) {
      if (i != 0) {
        if (M[i-1][j] == 1 || M[i][j] == 1) {
          set_dp(i,j,k, 0);
        } else {
          set_dp(i,j,k, dp[i-1][j][k^1]+1);
        }
      }
    } else {
      if (j != 0) {
        if (M[i][j-1] == 1 || M[i][j] == 1) {
          set_dp(i,j,k,0);
        } else {
          set_dp(i,j,k, dp[i][j-1][k^1]+1);
        }
      }
    }
  };

  auto update_stair = [&](int x, int y, int step, int del) {
    ll sum = 0;
    pair<int,int> s = {x,y};
    auto t = s;
    while (t.x >= 0 && t.x < n && t.y >= 0 && t.y < m) {
      // if (t!=s && M[t.x][t.y] == 1) {
      //   break;
      // }
      if (t != s) {
        update_dp(t.x,t.y,0);
        update_dp(t.x,t.y,1);
      }
      if (step == 0) {
        t.y += del;
      } else {
        t.x += del;
      }
      step ^= 1;
    }
  };

  
  auto update = [&](int x, int y, int c) {
    M[x][y] = c;
    ll old = 0;
    if (c == 1) {
      set_dp(x,y,0, 0);
      set_dp(x,y,1, 0);
      cur--;
    } else {
      update_dp(x,y,0);
      update_dp(x,y,1);
      cur++;
    }
    update_stair(x,y,0,1);
    update_stair(x,y,1,1);

  };


  int q;
  cin >> q;
  while(q--){
    int x,y;
    cin >> x >> y;
    --x,--y;
    update(x,y,M[x][y]^1);
    cout << cur << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();


  return 0;
}
