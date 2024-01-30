#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  ll ans = 0;
  ll pos = 0, neg = 0;
  for (int i=0;i<n;i++) {
    if (A[i] < 0) {
      int need = -A[i];
      if (pos < need) {
        ans += need-pos;
        pos = need;
      }
      pos -= need;
      neg += need;
    } else {
      int need = A[i];
      if (neg < need) {
        ans += need-neg;
        neg = need;
      }
      pos += need;
      neg -= need;
    }
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
