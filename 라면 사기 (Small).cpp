#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  array<int,2> cur = {};
  ll ans = 2*accumulate(begin(A),end(A), 0);
  for (int i=0;i<n;i++){
    int k = min(A[i], cur[1]);
    A[i] -= k;
    cur[1] -= k;
    ans += A[i];
    cur[1] = min(cur[0],k);
    cur[0] = A[i];
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
