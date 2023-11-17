#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1) {
    cout << 0 << "\n";
    return;
  }
  ll ans = 0;
  vector<int> g(n, -1);
  vector<int> dp(n);
  for (int i=n-2;i>=0;i--){
    int nxt = -1;
    if (g[i+1] == -1) {
      if (s[i] == '{' && s[i+1] == '}') {
        nxt = i+1;
      }
      if (s[i] == '(' && s[i+1] == ')') {
        nxt = i+1;
      }
    } else {
      if (g[i+1] + 1 < n) {
        if (s[i] == '{' && s[g[i+1]+1] == '}') {
          nxt = g[i+1]+1;
        }
        if (s[i] == '(' && s[g[i+1]+1] == ')') {
          nxt = g[i+1]+1;
        }
      }
    }
    if (nxt == -1) continue;
    if (nxt + 1 < n) {
      if (g[nxt+1] != -1) {
        g[i] = g[nxt+1];
        dp[i] = dp[nxt+1] + 1;
      } else {
        g[i] = nxt;
        dp[i] = 1;
      }
    } else {
      g[i] = nxt;
      dp[i] = 1;
    }
    ans += dp[i];
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t=0;t<T;t++){
    cout << "Case #" << t+1 << "\n";
    solve();
  }
}
