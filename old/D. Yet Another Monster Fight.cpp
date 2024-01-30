#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;
struct seg_tree {
  int n;
  vector<ll> bits;
  seg_tree(int n) : n(n), bits((n + 1) * 2, -inf) {}

  ll combine(ll a, ll b) { return max(a, b); }
  void update(int k, ll x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2)
      bits[k] = combine(bits[k * 2], bits[k * 2 + 1]);
  }
  ll query(int l, int r) {
    ll res = -inf;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1)
        res = combine(res, bits[l++]);
      if (!(r & 1))
        res = combine(res, bits[r--]);
    }
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  seg_tree st1(n), st2(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    st1.update(i, A[i] - i);
    st2.update(i, A[i] + i);
  }
  ll ans = inf;
  for (int i = 0; i < n; i++) {
    ll cand = A[i];
    cand = max(cand, st1.query(0, i - 1) + n - 1);
    cand = max(cand, st2.query(i + 1, n - 1));
    ans = min(ans, cand);
  }
  cout << ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
