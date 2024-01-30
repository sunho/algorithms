#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int ans = max(A[0], (x - A.back()) * 2);
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, A[i + 1] - A[i]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
