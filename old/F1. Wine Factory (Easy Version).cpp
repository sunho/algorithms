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
const ll inf = 1e18;
struct node {
  ll val = -inf;
  ll sf = -inf;
  friend node operator+(node lhs, node rhs) {
    node res;
    res.val = lhs.val + rhs.val;
    res.sf = max(rhs.sf, lhs.sf+rhs.val);
    return res;
  }
};

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> A(n);
  ll sum0 = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    sum0 += A[i];
  }
  vector<int> B(n);
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  vector<ll> C(n-1);
  for (int i=0;i<n-1;i++){
    cin >> C[i];
  }
  seg_tree<node> st(n);
  for (int i=0;i<n;i++){
    st.update(i,A[i]-B[i]);
  }
  while (q--) {
    int p,a,b;
    ll c;
    cin >> p >> a >> b >> c;
    --p;
    sum0 -= A[p];
    A[p] = a;
    B[p] = b;
    sum0 += A[p];
    st.update(p, A[p]-B[p]);
    pf += max(0ll, (ll)A[p]-B[p]);
    cout << sum0 - pf << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
