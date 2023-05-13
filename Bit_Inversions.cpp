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
  int val = -inf;
  int sz = 1;
  pair<int,int> left;
  pair<int,int> right;
  friend node operator+(node lhs, node rhs) {
		if (lhs.val == -inf) return rhs;
    if (rhs.val == -inf) return lhs;
    node res{};
    if (lhs.left.second == lhs.sz && rhs.left.first == lhs.left.first) {
      res.left = {lhs.left.first, lhs.left.second + rhs.left.second};
    } else {
      res.left = lhs.left;
    }
    if (rhs.right.second == rhs.sz && rhs.right.first == lhs.right.first) {
      res.right = {rhs.right.first, lhs.right.second + rhs.right.second};
    } else {
      res.right = rhs.right;
    }
    if (lhs.right.first == rhs.left.first) {
      res.val = max(res.val, lhs.right.second + rhs.left.second);
    }
    res.val = max({res.val, lhs.val, rhs.val, res.left.second, res.right.second});
    res.sz = lhs.sz + rhs.sz;
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;
  int n = s.size();
  seg_tree<node> st(n);
  for (int i=0;i<n;i++){
    node cur = {};
    cur.left = {s[i]-'0', 1};
    cur.right =  {s[i]-'0', 1};
    cur.val = 1;
    st.update(i, cur);
  }

  int q;
  cin >> q;
  while(q--){
    int k;
    cin >> k;
    --k;
    s[k] = s[k] == '0' ? '1' : '0';
    node cur = {};
    cur.left = {s[k]-'0', 1};
    cur.right =  {s[k]-'0', 1};
    cur.val = 1;
    st.update(k, cur);
    cout << st.query(0,n-1).val << " ";
  }
}
