#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> lvl1(n), lvl2(n);
  vector<vector<int>> comps(n);
  for (int i=1;i<n;i++){
    int p;
    cin >> p;
    --p;
    lvl1[i] = lvl1[p] + 1;
  }
  comps[0].push_back(0);
  for (int i=1;i<n;i++){
    int p;
    cin >> p;
    --p;
    lvl2[i] = lvl2[p] + 1;
    comps[lvl2[i]].push_back(i);
  }
  int ans = 0;
  for (int i=0;i<n;i++){
    set<int> S;
    for (int v : comps[i]) {
      S.insert(lvl1[v]);
    }
    ans = max(ans, (int)S.size());
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
