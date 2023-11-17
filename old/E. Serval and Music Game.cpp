#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int m = A.back();
  vector<ll> pf(m + 1);
  for (int i = 0; i < n; i++) {
    pf[A[i]]++;
  }
  for (int i = 0; i < m; i++) {
    pf[i + 1] += pf[i];
  }
  ll ans = 0;
  vector<array<int, 2>> cache(m + 1, array<int, 2>{-1, -1});
  for (int i = 1; i <= m; i++) {
    int a = m / i;
    int b = (m + i - 1) / i;
    auto &dp = a == b ? cache[a][0] : cache[a][1];
    if (dp != -1) {
      ans += (ll)dp * i;
      ans %= MOD;
      continue;
    }
    int r = a - 1;
    int cnt = n;
    for (int c = 1; c <= m; c += b, r += a) {
      if (c > r) {
        break;
      }
      cnt -= pf[r] - pf[c - 1];
    }
    dp = cnt;
    ans += (ll)dp * i;
    ans %= MOD;
  }
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
