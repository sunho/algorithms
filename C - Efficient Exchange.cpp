#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  const int N = 10;
  const int inf = 1e9;
  vector<int> dp(2);
  dp[0]=0;
  dp[1]=inf;
  for (int i=0;i<n;i++){
    int d = s[i]-'0';
    vector<int> nxt(2,inf);
    for (int j=0;j<2;j++){
      for (int k=0;k<2;k++){
        nxt[k] = min(nxt[k], dp[j]+(k==0?d:(j==1?10-d-1:10-d+1)));
      }
    }
    dp = nxt;
  }
  cout << min(dp[0],dp[1]) << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
