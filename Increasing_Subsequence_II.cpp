#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta, bits[v] += MOD, bits[v] %= MOD;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r], res %= MOD;
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  fenwick_tree ft(n);
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  auto vals = A;
  sort(begin(vals), end(vals));
  vals.resize(unique(begin(vals), end(vals))-begin(vals));
  for (int i=0;i<n;i++) A[i] = lower_bound(begin(vals), end(vals), A[i]) - begin(vals);
  for (int i=0;i<n;i++) {
    ll cnt = A[i] == 0 ? 1 : ft.query(A[i]-1)+1;
    ft.update(A[i], cnt);
  }
  cout << ft.query(n-1) << "\n";
}
