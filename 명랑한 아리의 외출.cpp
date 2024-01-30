#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ckmin(int& a, int b){ return b < a ? a = b, true : false; }
bool ckmax(int& a, int b){ return b > a ? a = b, true : false; }

void solve() {
  int n,m,t;
  cin >> n >> m >> t;
  vector<vector<int>> A(n, vector<int> (m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> A[i][j];
    }
  }
  vector<vector<int>> B(n, vector<int> (m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> B[i][j];
    }
  }
  const int inf = 1e9;
  vector<vector<vector<int>>> dp(t+1, vector<vector<int>>(n, vector<int>(m, -inf)));
  dp[0][0][0] = 0;
  for (int i=0;i<t;i++){
    for (int x=0;x<n;x++){
      for (int y=0;y<m;y++){
        pair<int,int> cands[] = {{x+1,y},{x,y+1},{x+1,y+1}};
        for (auto [u,v] : cands) {
          if (u >= n || v >= m) continue;
          if (i+B[u][v]+1<=t)
            ckmax(dp[i+B[u][v]+1][u][v], dp[i][x][y] + A[u][v]);
          ckmax(dp[i+1][u][v], dp[i][x][y]);
        }
      }
    }
  }
  int ans = -inf;
  for(int i=0;i<=t;i++){
    ans = max(ans, dp[i][n-1][m-1]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
