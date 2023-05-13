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
const int inf = 1e9;
struct node {
  ll val = 0;
  ll mn = inf;
  ll mx = -inf;
  friend node operator+(node lhs, node rhs) {
    if (lhs.mn == inf) return rhs;
    if (rhs.mn == inf) return lhs;
		node res;
    res.val = lhs.val + rhs.val;
    res.mn = min(rhs.mn, rhs.val + lhs.mn);
    res.mx = max(rhs.mx, rhs.val + lhs.mx);
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  seg_tree<node> st(n), st2(n);
  set<int> left, right;
  for (int i=0;i<n;i++){
    int x, t;
    cin >> x >> t;
    --x;
    if (t == 1) {
      st.update(x, {1,1,1});
      left.insert(x);
    } else {
      st.update(x, {-1,-1,-1});
      right.insert(x);
    }
    if (right.empty()) {
      cout << ">" << "\n";
      continue;
    }
    if (left.empty()) {
      cout << "<" << "\n";
      continue;
    }
    int l_mx = *--left.end(), r_mx = *--right.end();
    if (l_mx > r_mx) {
      if (left.size() < right.size()) {
        cout << "?" << "\n";
        continue;
      }
      if (st.query(0,n-1).mn < 0) {
        cout << "?" << "\n";
        continue;
      }
      cout << ">" << "\n";
    } else {
      if (left.size() > right.size()) {
        cout << "?" << "\n";
        continue;
      }
      if (st.query(0,n-1).mx > 0) {
        cout << "?" << "\n";
        continue;
      }
      cout << "<" << "\n";
    }
  }
}
