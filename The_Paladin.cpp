#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  const int inf = 1e8;

  vector<vector<int>> cost(26, vector(26, inf));
  int m = (k-1)/2;
  for (int i=0;i<n;i++){
    string s;
    cin >> s;
    int c;
    cin >> c;
    int u = s[0]-'a', v = s[1]-'a';
    cost[u][v] = c;
  }
  vector<int> dp(26, 0);
  for (int i=0;i<m;i++){
    vector<int> next(26, inf);
    for (int a=0;a<26;a++){
      for (int b=0;b<26;b++){
        next[b] = min(next[b], dp[a] + cost[a][b] + cost[b][a]);
      }
    }
    dp = next;
  }
  int ans = inf;
  for (int a=0;a<26;a++){
    if (k&1) {
      ans = min(ans, dp[a]);
    } else {
      ans = min(ans, dp[a]+cost[a][a]);
    }
  }
  if (ans == inf) cout << -1 << "\n";
  else cout << ans << "\n";
}
