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

  int n,q;
  cin >> n >> q;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  vector<int> values(begin(A),end(A));
  sort(begin(values), end(values));
  values.resize(unique(begin(values), end(values)) - begin(values));
  for (int i=0;i<n;i++) 
    A[i] = lower_bound(begin(values), end(values), A[i]) - begin(values);
  fenwick_tree ft(n);
  vector<vector<pair<int,int>>> queries(n);
  vector<int> last_index(values.size(), -1);
  for (int i=0;i<q;i++){
    int l,r;
    cin >> l >> r;
    --l,--r;
    queries[l].push_back({r, i});
  }

  vector<int> ans(q);
  for (int i=n-1;i>=0;i--){
    if (last_index[A[i]] != -1) {
      ft.update(last_index[A[i]],-1);
    }
    ft.update(i, 1);
    last_index[A[i]] = i;
    for (auto [r, qi] : queries[i]) {
      ans[qi] = ft.query(i, r);
    }
  }
  for (int i=0;i<q;i++){
    cout << ans[i] << "\n";
  }
}
