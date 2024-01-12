#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int,set<int>> dp;
  vector<int> divisors;
  for (int i=2;i*i<=n;i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      divisors.push_back(n/i);
    }
  }
  divisors.push_back(n);
  sort(begin(divisors),end(divisors));
  vector<vector<int>> factors(divisors.size());
  for (int i=0;i<divisors.size();i++){
    for (int j=0;j<=i;j++) {
      if (divisors[i] % divisors[j] == 0)
        factors[i].push_back(divisors[j]);
    }
  }
  auto dfs = [&](auto&& self, int m) {
    if (dp.count(m)) {
      return dp[m];
    }
    set<int> res; 
    int l = lower_bound(begin(divisors),end(divisors), m) - begin(divisors);
    for (int d : factors[l]) {
      if (d != m) {
        auto L = self(self, d);
        for (auto x : L) {
          res.insert(m/d - 1 + x);
        }
      } else {
        res.insert(d-1);
      }
    }
    return dp[m] = res;
  };
  auto ans = dfs(dfs, n);
  cout << ans.size() << "\n";
  for (int x : ans) {
    cout << x << " ";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
