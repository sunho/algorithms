#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
using ll = long long;

void solve() {
  int n, c;
  cin >> n >> c;
  int m = n / 2;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<ll> left;
  for (int msk = 0; msk < (1 << m); msk++) {
    ll sum = 0;
    for (int j = 0; j < m; j++) {
      if ((msk >> j) & 1) {
        sum += A[j];
      }
    }
    if (sum > c)
      continue;
    left.push_back(sum);
  }
  sort(begin(left), end(left));
  ll ans = 0;
  int rem = n - m;
  for (int msk = 0; msk < (1 << rem); msk++) {
    ll sum = 0;
    for (int j = 0; j < rem; j++) {
      if ((msk >> j) & 1) {
        sum += A[m + j];
      }
    }
    if (sum > c)
      continue;
    int cnt = upper_bound(begin(left), end(left), c - sum) - begin(left);
    ans += cnt;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
