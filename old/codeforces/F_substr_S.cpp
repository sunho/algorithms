#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
  string s;
  ll L, R;
  cin >> s >> L >> R;
  auto go = [&](string t) {
    const int n = t.size();
    const int m = s.size();
    vector dp(4, vector(n+1, vector(m+1, 0ll)));
    dp[0][0][0] = 1;
    for (int i=0;i<n;i++){
      vector next(4, vector(n+1, vector(m+1, 0ll)));
      for (int j=0;j<=i;j++) {
        for (int k=0;k<=min(m,i);k++) {
          for (int d=0;d<=9;d++){
            for (int z=0;z<2;z++){
              int nk;
              if (k < m && d == s[k] - '0') {
                nk = k+1;
              } else {
                string ss = s.substr(0, k);
                auto pi = prefix_function(ss + "$" + ss + string(1, '0'+d));
                nk = pi.back();
              }
              int zz = z << 1;
              int nz = z | (d!=0);
              if (nz == 0) nk = 0;
              int nj = nk == m ? min(j + 1,n) : j;
              int nzz = nz << 1;
              if (d == t[i]-'0') {
                next[nzz|0][nj][nk] += dp[zz|0][j][k];
              } else if (d < t[i]-'0') {
                next[nzz|1][nj][nk] += dp[zz|0][j][k];
              }
              next[nzz|1][nj][nk] += dp[zz|1][j][k];
            }
          }
        }
      }
      dp = move(next);
    }
    ll res = 0;
    for (int z=0;z<4;z++){
      for (int j=1;j<=n;j++) {
        for (int k=0;k<=m;k++) {
          res += j * dp[z][j][k];
        }
      }
    }
    return res;
  };
  cout << go(to_string(R)) - go(to_string(L-1)) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
