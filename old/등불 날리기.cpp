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
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  vector<int> vals;
  for (int i=0;i<n;i++){
    cin >> A[i];
    vals.push_back(A[i]);
  }
  sort(begin(vals),end(vals));
  vals.resize(unique(begin(vals),end(vals))-begin(vals));
  for (int i=0;i<n;i++){
    A[i] = lower_bound(begin(vals),end(vals),A[i]) - vals.begin();
  }
  int m = vals.size();
  ll cur = 0;
  fenwick_tree ft(m);
  for (int i=0;i<k;i++){
    cur += ft.query(0, A[i]-1);
    ft.update(A[i],1);
  }
  ll ans = cur;
  for (int i=k;i<n;i++) {
    cur -= ft.query(A[i-k]+1,m-1);
    ft.update(A[i-k],-1);
    cur += ft.query(0, A[i]-1);
    ft.update(A[i],1);
    ans = max(ans, cur);
  }
  cout << ans << "\n";
}
