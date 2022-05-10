#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  const int inf = 1e9;
  vector<int> p(n+1);
  vector<int> dp(n+1, inf);
  dp[n] = 0;
  p[n] = -1;
  for(int i=n;i>=1;i--) {
    if (i % 2 == 0) {
      if (ckmin(dp[i/2], dp[i] + 1)) {
        p[i/2] = i;
      }
    }
    if (i % 3 == 0) {
      if (ckmin(dp[i/3], dp[i] + 1)) {
        p[i/3] = i;
      }
    }
    if (ckmin(dp[i-1], dp[i]+1)) {
      p[i-1] = i;
    }
  }
  cout << dp[1] << "\n";
  stack<int> s;
  int u = 1;
  while (u != -1) {
    s.push(u);
    u = p[u];
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
