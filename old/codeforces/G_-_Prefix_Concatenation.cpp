#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
  string s, t;
  cin >> s >> t;
  int n = t.size();
  string s_t = s + "$" + t;
  auto Z_sup = prefix_function(s_t);
  auto Z = vector<int>(Z_sup.begin() + s.size() + 1, Z_sup.end());
  reverse(all(Z));
  const int INF = 1e9;
  vector<int> dp(n+1, INF);
  dp[0] = 0;
  for(int i=0;i<n;i++){
    ckmin(dp[i+Z[i]], dp[i]+1);
  }
  if (dp[n] == INF)
    cout << -1 << "\n";
  else
    cout << dp[n] << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
