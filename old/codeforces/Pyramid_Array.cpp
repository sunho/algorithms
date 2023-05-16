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
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  vector<int> vals = A;
  sort(begin(vals), end(vals));
  for (int i=0;i<n;i++) A[i] = lower_bound(begin(vals), end(vals), A[i]) - begin(vals);
  vector<int> inv(n);
  for (int i=0;i<n;i++) inv[A[i]] = i;
  fenwick_tree ft(n);
  for (int i=0;i<n;i++){
    ft.update(i,1);
  }
  ll ans = 0;
  for (int i=0;i<n;i++){
    int k = inv[i];
    int left = k == 0 ? 0 : ft.query(0,k-1);
    int right = k == n-1 ? 0 : ft.query(k+1,n-1);
    ans += min(left, right);
    ft.update(k,-1);
  }
  cout << ans << "\n";
}
