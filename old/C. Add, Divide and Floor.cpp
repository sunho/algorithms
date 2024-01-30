#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int mn = *min_element(begin(A), end(A));
  int c = mn;
  int mx = *max_element(begin(A), end(A));
  int ans = 0;
  while (mn != mx) {
    mx = (mx + mn) / 2;
    ans++;
  }
  cout << ans << "\n";
  if (ans != 0 && ans <= n) {
    for (int i = 0; i < ans; i++) {
      cout << mn << " ";
    }
    cout << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
