#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void update(int v, int delta) {
    for (++v; v <= n; v += v & (-v))
      bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r & (-r))
      res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l - 1); }
};


void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> A(n);
  vector<int> B(m);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    A[--a] = i;
  }
  vector<int> vals;
  for (int i=0;i<m;i++){
    cin >> B[i];
    vals.push_back(B[i]);
  }
  sort(begin(vals),end(vals));
  vals.resize(unique(begin(vals),end(vals))-begin(vals));
  for (int i=0;i<m;i++){
    B[i] = lower_bound(begin(vals), end(vals), B[i]) - begin(vals);
  }
  fenwick_tree ft(n+m);
  vector<int> M(n);
  for (int i=0;i<n;i++){
    M[i] = ft.query(0,A[i]-1);
    ft.update(A[i], 1);
  }
  ft = fenwick_tree(n+m);

  auto match = [&](int i, int a) {
    if (i == n) return false;
    return ft.query(0, a-1) == M[i];
  };
  vector<int> pf(n);
  for (int i=1;i<n;i++){
    int j = pf[i-1];
    while (j > 0 && !match(j, A[i])) {
      for (int k=i-j;k<i-pf[j-1];k++){
        ft.update(A[k], -1);
      }
      j = pf[j-1];
    }
    if (match(j, A[i])) {
      ft.update(A[i], 1);
      j++;
    }
    pf[i] = j;
  }
  ft = fenwick_tree(n+m);
  vector<int> ans;
  int len = 0;
  for (int i=0;i<m;i++){
    while (len > 0 && !match(len, B[i])) {
      int nxt = pf[len-1];
      for (int k=i-len;k<i-nxt;k++){
        ft.update(B[k], -1);
      }
      len = nxt;
    }
    if (match(len, B[i])) {
      ft.update(B[i], 1);
      len++;
    }
    if (len == n) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << "\n";
  for (int i : ans) {
    cout << i - n + 2 << " ";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
