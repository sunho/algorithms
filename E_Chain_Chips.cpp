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
  array<array<ll, 2>,2> dp;
  node() {
    dp[0][0] = 0;
    dp[0][1] = dp[1][0] = dp[1][1] = inf;
  }
  friend node operator+(node lhs, node rhs) {
    if (lhs.dp[1][1] == inf) return rhs;
    if (rhs.dp[1][1] == inf) return lhs;
    node res;
    for (int i=0;i<2;i++){
      for (int j=0;j<2;j++){
        res.dp[i][j] = min({inf, lhs.dp[i][0]+rhs.dp[1][j], lhs.dp[i][1]+rhs.dp[0][j]});
      }
    }
    return res;
  }
};


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n-1);
  seg_tree<node> st(n-1);
  for (int i=0;i<n-1;i++){
    cin >> A[i];
    node cur;
    cur.dp[0][1] = cur.dp[1][0] = cur.dp[1][1] = 2*A[i];
    st.update(i, cur);
  }

  int q;
  cin >> q;
  while (q--){
    int k,x;
    cin >> k >> x;
    --k;
    node cur;
    cur.dp[0][1] = cur.dp[1][0] = cur.dp[1][1] = 2*x;
    st.update(k, cur);
    auto res = st.query(0, n-2);

    cout << res.dp[1][1] << "\n";
  }
}
