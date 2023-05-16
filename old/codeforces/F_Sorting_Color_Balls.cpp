#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l-1); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;

  vector<vector<int>> B(n);
  vector<int> C(n);
  vector<int> A(n);

  for (int i=0;i<n;i++) cin >> C[i], C[i]--;
  for (int i=0;i<n;i++) cin >> A[i], A[i]--;
  for (int i=0;i<n;i++){
    B[C[i]].push_back(A[i]);
  }
  fenwick_tree ft(n+1);
  auto calc_inv = [&](const vector<int>& arr) {
    ll res = 0;
    for (int i=0;i<arr.size();i++){
      res += ft.query(arr[i]+1, n);
      ft.update(arr[i], 1);
    }
    for (int i=0;i<arr.size();i++){
      ft.update(arr[i], -1);
    }
    return res;
  };

  ll ans = calc_inv(A);
  for (auto& arr : B) {
    ans -= calc_inv(arr);
  }
  cout << ans << "\n";
}
