#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> A(m);
  for (int i=0;i<m;i++){
    cin >> A[i];
  }
  vector<int> id(m);
  iota(begin(id),end(id),0);
  ranges::sort(id, [&](int i, int j) {
    return A[i] > A[j];
  });
  int cur = 0;
  vector<int> ans;
  for (int i=0;i<m;i++){
    if (A[id[i]] > 2*n) continue;
    cur += A[id[i]];
    ans.push_back(id[i]);
    if (cur >= n) {
      break;
    }
  }
  cout << ans.size() << "\n";
  for (int i : ans) {
    cout << i + 1 << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
