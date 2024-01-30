#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// generic seg tree
template <class T> struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n + 1) * 2) {}

  void update(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2)
      bits[k] = bits[k * 2] + bits[k * 2 + 1];
  }
  T query(int l, int r) {
    T resl = {}, resr = {};
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1)
        resl = resl + bits[l++];
      if (!(r & 1))
        resr = bits[r--] + resr;
    }
    return resl + resr;
  }
};
const int inf = 1e9;
struct node {
  int val = -inf;
  friend node operator+(node lhs, node rhs) { return {max(lhs.val, rhs.val)}; }
};

void solve() {
  int n;
  cin >> n;
  vector<ll> pf(n + 1);
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    pf[i + 1] += A[i];
  }
  for (int i = 0; i < n; i++) {
    pf[i + 1] += pf[i];
  }
  auto vals = pf;
  sort(begin(vals), end(vals));
  vals.resize(unique(begin(vals), end(vals)) - begin(vals));
  for (int i = 0; i <= n; i++) {
    pf[i] = lower_bound(begin(vals), end(vals), pf[i]) - begin(vals);
  }
  int m = vals.size();
  seg_tree<node> dp(m + 1);
  vector<int> dp2(m + 1, -inf);
  int zero = lower_bound(begin(vals), end(vals), 0) - begin(vals);
  dp.update(zero, {0});
  dp2[zero] = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int nw = dp2[pf[i]];
    int cur = dp2[pf[i - 1]];
    if (A[i - 1] == 0) {
      nw = max(nw, cur);
    } else if (A[i - 1] < 0) {
      nw = max(nw, cur - 1);
    }
    nw = max(nw, dp.query(0, pf[i] - 1).val + i);
    dp2[pf[i]] = nw;
    if (i == n) {
      ans = nw;
    }
    int old = dp.query(pf[i], pf[i]).val;
    dp.update(pf[i], {max(nw - i, old)});
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
