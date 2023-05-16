#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pf[7][7];

ll sum(int x, int y, int x2, int y2) {
  return pf[x2+1][y2+1] - pf[x][y2+1] - pf[x2+1][y] + pf[x][y];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int h,w,t;
  cin >> h >> w >> t;

  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++) {
      cin >> pf[i+1][j+1];
    }
  }

  for (int i=1;i<=h;i++){
    for (int j=1;j<=w;j++){
      pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + pf[i][j];
    }
  }

  const ll inf = 1e18;

  ll ans = inf;
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      for (int ii=i;ii<h;ii++){
        for (int jj=j;jj<w;jj++) {
          ll mn = sum(i,j,ii,jj);
          ll dp[37][7][7][7][7];
          for (int i=0;i<h;i++)
            for (int j=0;j<w;j++)
              for (int ii=i;ii<h;ii++)
                for (int jj=j;jj<w;jj++) 
                  if (sum(i,j,ii,jj) >= mn) {
                    dp[0][i][j][ii][jj] = sum(i,j,ii,jj);
                  } else {
                    dp[0][i][j][ii][jj] = inf;
                  }
          for (int k=1;k<=t;k++){
            for (int i=0;i<h;i++){
              for (int j=0;j<w;j++){
                for (int ii=i;ii<h;ii++){
                  for (int jj=j;jj<w;jj++) {
                    auto& res = dp[k][i][j][ii][jj];
                    res = inf;
                    for (int kk=0;kk<k;kk++){
                      for (int c=i+1;c<=ii;c++){
                        ll cand1 = min(dp[kk][i][j][c-1][jj], dp[k-kk-1][c][j][ii][jj]);
                        ll cand2 = min(dp[k-kk-1][i][j][c-1][jj], dp[kk][c][j][ii][jj]);
                        if (cand1 >= mn) res = min(res, max(dp[kk][i][j][c-1][jj], dp[k-kk-1][c][j][ii][jj]));
                        if (cand2 >= mn) res = min(res, max(dp[k-kk-1][i][j][c-1][jj], dp[kk][c][j][ii][jj]));
                      }
                      for (int c=j+1;c<=jj;c++){
                        ll cand1 = min(dp[kk][i][j][ii][c-1], dp[k-kk-1][i][c][ii][jj]);
                        ll cand2 = min(dp[k-kk-1][i][j][ii][c-1], dp[kk][i][c][ii][jj]);
                        if (cand1 >= mn) res = min(res, max(dp[kk][i][j][ii][c-1], dp[k-kk-1][i][c][ii][jj]));
                        if (cand2 >= mn) res = min(res, max(dp[k-kk-1][i][j][ii][c-1], dp[kk][i][c][ii][jj]));
                      }
                    }
                  }
                }
              }
            }
          }
          ll res = dp[t][0][0][h-1][w-1];
          if (res != inf)
            ans = min(ans, res-mn);
        }
      }
    }
  }

  cout << ans << "\n";
}
