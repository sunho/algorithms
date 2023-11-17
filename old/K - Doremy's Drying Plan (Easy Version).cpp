#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> imos(n+1);
  vector<vector<int>> A(n);
  for (int i=0;i<m;i++) {
    int l, r;
    cin >> l >> r;
    --l,--r;
    A[l].push_back(r);
    imos[l]++;
    imos[r+1]--;
  }
  for (int i=0;i<n;i++) {
    imos[i+1] += imos[i];
  }
  vector<int> pf1(n+1);
  vector<int> pf2(n+1);
  for (int i=0;i<n;i++) {
    pf1[i+1] = pf1[i] + (imos[i] == 1);
    pf2[i+1] = pf2[i] + (imos[i] == 2);
  }
  int zero = 0;
  for (int i=0;i<n;i++){
    if (imos[i] == 0) zero++;
  }
  int ans = zero;
  map<int,vector<pair<int,int>>> exits;
  multiset<pair<int,int>> active;
  multiset<int> ends;
  for (int i=0;i<n;i++){
    for (auto [l,r] : exits[i]) {
      active.erase(active.find({l,r}));
      ends.erase(ends.find(r));
    }
    for (int r : A[i]) {
      exits[r+1].push_back({i,r});
      active.insert({i,r});
      ends.insert(r);
    }
    if (!active.empty()) {
      auto [l,r] = *active.begin();
      int r2 = *--ends.end();
      ans = max(ans, zero+pf1[r2+1]-pf1[l]);
    }
    if (active.size() == 2) {
      auto [l1,r1] = *active.begin();
      auto [l2,r2] = *++active.begin();
      int l = min(l1,l2);
      int r = max(r1,r2);
      ans = max(ans, zero+pf1[r+1]-pf1[l]+pf2[min(r1,r2)+1]-pf2[max(l1,l2)]);
    }
  }
  const int inf = 1e9;
  vector<vector<int>> dp(n+1,vector<int>(3, -inf));
  dp[0][0] = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<2;j++){
      for (int r : A[i]) {
        dp[r+1][j+1] = max(dp[r+1][j+1],dp[i][j]+pf1[r+1]-pf1[i]);
      }
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }
    dp[i+1][2] = max(dp[i+1][2], dp[i][2]);
  }
  ans = max(ans,dp[n][2]+zero);
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
