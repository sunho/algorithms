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
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(3)));
  dp[0][0][0] = 0;
  dp[0][0][1] = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      dp[i][j][2] = 1;
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if (i==0 && j==0)continue;
      if (i != 0) dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j][2];
      if (j != 0) dp[i][j][0] = dp[i][j-1][1]+dp[i][j-1][2];
    }
  }
  ll cur = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      for(int k=0;k<3;k++) {
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
    if (M[i][j] == 1) {
      set_dp(i,j,k,0);
      return;
    }
    if (k == 1) if (i != 0) set_dp(i,j,1, dp[i-1][j][0]+dp[i-1][j][2]);
    if (k == 0) if (j != 0) set_dp(i,j,0, dp[i][j-1][1]+dp[i][j-1][2]);
  };
  int q;
  cin >> q;
  while(q--){
    int x,y;
    cin >> x >> y;
    --x,--y;
    M[x][y]^=1;
    ll old = 0;
    if (M[x][y] == 1) {
      set_dp(x,y,0,0);
      set_dp(x,y,1,0);
      set_dp(x,y,2,0);
    } else {
      set_dp(x,y,2,1);
    }
    for (int k = 0; k < 2; k++) {
      int step = k;
      int i = x;
      int j = y;
      while (i >= 0 && i < n && j >= 0 && j < m) {
        update_dp(i,j,0);
        update_dp(i,j,1);
        if (step == 0) {
          i += 1;
        } else {
          j += 1;
        }
        step ^= 1;
      }
    }
    cout << cur << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();


  return 0;
}
