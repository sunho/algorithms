#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  bool zero = false;
  vector<vector<int>> B(2);
  for (int i = 0; i < n; i++) {
    if (A[i] == 0) {
      zero = true;
    } else if (A[i] < 0) {
      B[0].push_back(A[i]);
    } else {
      B[1].push_back(A[i]);
    }
  }
  sort(rbegin(B[0]), rend(B[0]));
  sort(begin(B[1]), end(B[1]));
  int lsz = B[0].size();
  int rsz = B[1].size();
  const ll inf = 1e18;
  ll ans = 0;
  for (int t = 1; t <= n; t++) {
    vector<vector<array<ll, 2>>> dp(
        lsz + 1, vector<array<ll, 2>>(rsz + 1, array<ll, 2>{inf, inf}));
    auto dfs = [&](auto &&self, int i, int j, int state) -> ll {
      if (i == 0 && j == 0)
        return 0;
      ll &ndp = dp[i][j][state];
      if (ndp != inf)
        return ndp;
      if (i + j > t) {
        ll cand = inf;
        for (int z = 0; z < 2; z++) {
          if (i - 1 >= 0)
            cand = min(cand, self(self, i - 1, j, z));
          if (j - 1 >= 0)
            cand = min(cand, self(self, i, j - 1, z));
        }
        return ndp = cand;
      }
      if (state == 1)
        swap(i, j);
      auto call = [&](int i, int j, int z) {
        if (state == 0) {
          return self(self, i, j, z);
        } else {
          return self(self, j, i, z);
        }
      };
      int sz = i + j - 1;
      int cur;
      if (i == 0) {
        return inf;
      }
      cur = B[state][i - 1];
      ll cand = inf;
      if (j == 0) {
        cand = min(cand, (ll)abs(cur) * (t - sz));
      } else {
        cand = min(cand, call(i, j - 1, state ^ 1) +
                             abs(cur - (j == 1 ? 0 : B[state ^ 1][j - 2])) *
                                 (t - sz));
      }
      if (i == 0) {
        cand = min(cand, (ll)abs(cur) * (t - sz));
      } else {
        cand =
            min(cand, call(i - 1, j, state) +
                          abs(cur - (i == 1 ? 0 : B[state][i - 2])) * (t - sz));
      }
      return ndp = cand;
    };
    ans = max(ans, m * t - dfs(dfs, lsz, rsz, 0));
    ans = max(ans, m * t - dfs(dfs, lsz, rsz, 1));
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
