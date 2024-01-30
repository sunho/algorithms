#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, t;
  cin >> n >> t;
  vector<vector<int>> A(t);
  for (int i=0;i<n;i++){
    int l, r;
    cin >> l >> r;
    --l,--r;
    A[l].push_back(r);
  }
  int exit = 0;
  int ans = 0;
  int mx = 0;
  for (int i=0;i<t;i++){
    for (int r : A[i]) {
       mx = max(mx, r+1);
    }
    if (exit == i) {
      ans ++;
      if (mx == exit) {
        cout << -1 << "\n";
        return;
      }
      exit = mx;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
