const ll inf = 1e18;
template<class T, T def, auto combine>
struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, def) {}
  void set(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  T get(int i) {
    return bits[i+n];
  }
  T query(int l, int r) {
    T res = def;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

ll combine_max(ll a, ll b) { return max(a,b); }
using max_seg_tree = seg_tree<ll,-inf,combine_max>;

ll combine_min(ll a, ll b) { return min(a,b); }
using min_seg_tree = seg_tree<ll,inf,combine_min>;

// generic seg tree
template <class T> struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n+1)*2) {}

  void set(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = bits[k*2] + bits[k*2+1];
  }
  T get(int i) {
    return bits[i+n];
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
  ll val = -inf;
  friend node operator+(node lhs, node rhs) {
		return {max(lhs.val, rhs.val)};
  }
};
