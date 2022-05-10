#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  string s;
  cin >> s;
  vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
  auto is_palin = [&](int l, int r, auto&& self) -> bool {
    int n = (r-l+1);
    if (n == 1) return true;
    if (n == 0) return true;
    if (memo[l][r] != -1) return memo[l][r];
    if (s[l] == s[r]) {
      memo[l][r] = self(l+1, r-1, self); 
      return memo[l][r];
    }
    memo[l][r] = false;
    return memo[l][r];
  };

  int n = (int)s.size();
  const int inf = 1e9;
  vector<int> dp(n+1, inf);
  dp[0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<i;j++){
      if (is_palin(j,i-1, is_palin)) {
        ckmin(dp[i], dp[j] + 1);
      }
    }
  }
  cout << dp[n] << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
