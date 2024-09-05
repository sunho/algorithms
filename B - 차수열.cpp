#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#else
#define dbg(x...) 
#endif


void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<vector<int>> ans(n, vector<int>(n));
  vector<pair<int,int>> rem;
  for (int i=0;i<n;i++){
    if (A[i])
      rem.push_back({A[i],i});
  }
  sort(rbegin(rem),rend(rem));
  while (!rem.empty()) {
    if (rem.size() == 1) {
      cout << -1 << "\n";
      return;
    }
    for (int i=1;i<(int)rem.size()&&rem[0].first;i++){
      if (!ans[rem[0].second][rem[i].second]) {
        ans[rem[0].second][rem[i].second] = 1;
        ans[rem[i].second][rem[0].second] = 1;
        rem[0].first--;
        rem[i].first--;
      }
    }
    if (rem[0].first != 0) {
      cout << -1 << "\n";
      return;
    }
    sort(rbegin(rem),rend(rem));
    while (!rem.empty() && rem.back().first == 0) {
      rem.pop_back();
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
