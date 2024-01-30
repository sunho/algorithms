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
  ll ans = 0;
  int last = A[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    int div = (A[i] + last - 1) / last;
    ans += div - 1;
    last = A[i] / div;
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
