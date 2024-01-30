#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  string s,t;
  cin >> s >> t;
  const int inf = 1e9;
  vector<int> dp(m+1);
  iota(begin(dp),end(dp),0);
  auto cmp = [](char a, char b) {
    if (a == 'i' && (b == 'i' || b == 'j' || b == 'l')) {
      return true;
    }
    if (a == 'v' && (b == 'v' || b == 'w')) {
      return true;
    }
    return a == b;
  };
  for (int i=0;i<n;i++){
    vector<int> nxt(m+1,0);
    for (int j=0;j<=m;j++){
      nxt[j] = min({dp[j]+1, j==0?inf:nxt[j-1]+1});
      int rep = j > 0 ? dp[j-1] + !cmp(s[i], t[j-1]) : inf;
      nxt[j] = min(nxt[j], rep);
    }
    dp = nxt;
  }
  cout << dp[m] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
