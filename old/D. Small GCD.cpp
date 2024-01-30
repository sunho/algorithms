#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> cnt(N + 1);
  vector<ll> cnt2(N + 1);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(begin(A), end(A));
  for (int i = 0; i < n; i++) {
    cnt[A[i]]++;
    cnt2[A[i]] += n - i - 1;
  }
  const int mx = *max_element(begin(A), end(A));
  vector<__int128_t> dp(mx + 1);
  for (int x = mx; x >= 1; x--) {
    ll sum = 0;
    for (int y = x; y <= mx; y += x) {
      dp[x] += (__int128_t)cnt2[y] * sum;
      sum += cnt[y];
    }
    for (int y = 2 * x; y <= mx; y += x) {
      dp[x] -= dp[y];
    }
  }
  ll ans = 0;
  for (int i = 1; i <= mx; i++) {
    ans += i * dp[i];
  }
  map<int, int> cnt3;
  for (int i = 0; i < n; i++) {
    ans += (ll)A[i] * cnt3[A[i]] * (n - i - 1);
    cnt3[A[i]]++;
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
