#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  string s,t;
  cin >> s >> t;
  vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));
  int n = (int)s.size();
  int m = (int)t.size();
  vector<vector<bool>> added(n+1,vector<bool>(m+1));
  vector<vector<pair<int,int>>> p(n+1,vector<pair<int,int>>(m+1,{-1,-1}));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if (ckmax(dp[i][j], dp[i-1][j])) p[i][j] = {i-1,j};
      if (ckmax(dp[i][j], dp[i][j-1])) p[i][j] = {i,j-1};
      if (s[i-1]==t[j-1] && ckmax(dp[i][j], dp[i-1][j-1] + 1)) {
        p[i][j] = {i-1,j-1};
        added[i][j] = true;
      }
    }
  }
  cout << dp[n][m] << "\n";
  if (dp[n][m] != 0) {
    string ans;
    pair<int,int> v = {n,m};
    while (v != make_pair(-1,-1)) {
      auto u = p[v.first][v.second];
      if (added[v.first][v.second]) {
        ans.push_back(s[u.first]);
      }
      v = u;
    }
    reverse(all(ans));
    cout << ans << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
