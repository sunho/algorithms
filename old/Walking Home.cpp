#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<vector<char>> M(n, vector<char>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> M[i][j];
    }
  }
  auto dfs = [&](auto&& self, array<int,2> cur, int state, int tot) -> ll {
    ll res = 0;
    while (cur[state] < n - 1) {
      cur[state]++;
      if (M[cur[0]][cur[1]] == 'H') break;
      if (tot < k && (cur[0] != n - 1 || cur[1] != n-1)) {
        res += self(self, cur, state^1, tot+1);
      }
    }
    if (cur[0] == n-1 && cur[1] == n-1) {
      res += 1;
    }
    return res;
  };
  cout << dfs(dfs, {0,0}, 0, 0) + dfs(dfs, {0,0}, 1, 0) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
