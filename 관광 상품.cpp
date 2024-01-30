#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// generic seg tree
template <class T> struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n+1)*2) {}

  void update(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = bits[k*2] + bits[k*2+1];
  }
  T query(int l, int r) {
    T resl = {}, resr = {};
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) resl = resl + bits[l++];
      if (!(r & 1)) resr = bits[r--] + resr;
    }
    return resl + resr;
  }
};
const ll inf = 1e9;
struct node {
  ll val = 0;
  ll pf = -inf;
  ll sf = -inf;
  friend node operator+(node lhs, node rhs) {
    if (lhs.pf == -inf) return rhs;
    if (rhs.pf == -inf) return lhs;
    node res;
    res.val = lhs.val+rhs.val;
    res.pf = max(lhs.pf, lhs.val + rhs.pf);
    res.sf = max(rhs.sf, rhs.val + lhs.sf);
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> id(n);
  iota(begin(id),end(id),0);
  sort(begin(id),end(id),[&](int i, int j) {
    return A[i] > A[j];
  });
  seg_tree<node> st(n);
  for (int i=0;i<n;i++){
    st.update(i, {-1,-1,-1});
  }
  int ans = 0;
  int cur = 0;
  for (int i : id) {
    while (cur < n && A[id[cur]] >= A[i]) {
      st.update(id[cur], {1,1,1});
      cur++;
    }
    if (st.query(i+1,n-1).pf >= 0) {
      ans = max(ans, A[i]);
    }
    if (st.query(0,i-1).sf >= 0) {
      ans = max(ans, A[i]);
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
