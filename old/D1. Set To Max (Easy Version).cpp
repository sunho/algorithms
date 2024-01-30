#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e9;

// Lazy Segment Tree
template <class Info, class Tag> struct lazy_seg_tree {
  int n;
  vector<Info> info;
  vector<Tag> lazy;
  lazy_seg_tree(int n) : n(n), info(4 * n), lazy(4 * n) {
    auto build = [&](auto &&self, int v, int l, int r) {
      if (l == r) {
        return;
      } else {
        int m = (l + r) / 2;
        self(self, v * 2, l, m);
        self(self, v * 2 + 1, m + 1, r);
        info[v] = info[v * 2] + info[v * 2 + 1];
      }
    };
    build(build, 1, 0, n - 1);
  }
  void apply(int v, const Tag &tag) {
    info[v].apply(tag);
    lazy[v].apply(tag);
  }
  void push(int v) {
    apply(2 * v, lazy[v]);
    apply(2 * v + 1, lazy[v]);
    lazy[v] = {};
  }
  void pull(int v) { info[v] = info[2 * v] + info[2 * v + 1]; }
  void update(int v, int l, int r, int x, const Info &val) {
    if (l == r) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    push(v);
    if (x <= m)
      update(2 * v, l, m, x, val);
    else
      update(2 * v + 1, m + 1, r, x, val);
    pull(v);
  }
  void update(int x, const Info &val) { update(1, 0, n - 1, x, val); }
  void range_apply(int v, int l, int r, int x, int y, const Tag &tag) {
    if (l > y || r < x)
      return;
    if (l >= x && r <= y) {
      apply(v, tag);
      return;
    }
    int m = (l + r) / 2;
    push(v);
    range_apply(2 * v, l, m, x, y, tag);
    range_apply(2 * v + 1, m + 1, r, x, y, tag);
    pull(v);
  }
  void range_apply(int l, int r, const Tag &tag) {
    range_apply(1, 0, n - 1, l, r, tag);
  }
  Info query(int v, int l, int r, int x, int y) {
    if (l > y || r < x)
      return {};
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    push(v);
    return query(2 * v, l, m, x, y) + query(2 * v + 1, m + 1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
struct tag {
  bool set = false;
  ll add = 0;
  tag(bool set, ll add) : set(set), add(add) {}
  tag() : set(false), add(0) {}
  void apply(tag t) {
    if (t.set) {
      set = true;
      add = t.add;
    }
  }
};
struct node {
  int val = -inf;
  node(int val) : val(val) {}
  node() : val(-inf) {}
  friend node operator+(node lhs, node rhs) {
    node res;
    res.val = max(lhs.val, rhs.val);
    return res;
  }
  void apply(tag t) {
    if (t.set)
      val = t.add;
  }
};

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
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n);
  vector<pair<int,int>> q;
  lazy_seg_tree<node, tag> st(n);
  fenwick_tree ft(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    st.update(i, {A[i]});
  }
  for (int i=0;i<n;i++){
    cin >> B[i];
    q.push_back({B[i],i});
  }
  sort(begin(q),end(q));
  int ptr = 0;
  auto q2 = q;
  vector<int> vis(n);
  bool yes = true;
  for (int i=0;i<n;i++){
    auto [a, j] = q[i];
    if (vis[j]) {
      continue;
    }
    while (ptr < n && q[ptr].first < a) {
      ft.update(q[ptr].second, 1);
      ptr++;
    }
    vis[j] = true;
    int found = -1;
    if (st.query(j,j).val > B[j]) {
      yes = false;
    }
    if (st.query(j,j).val == B[j]) {
      found = j;
    }
    int r = j+1;
    while (r < n && B[r] == B[j]) {
      vis[r] = true;
      if (st.query(r,r).val > B[j]) {
        yes = false;
      }
      if (st.query(r,r).val == B[j]) {
        found = r;
      }
      r++;
    }
    if (found == -1) {
      int ng = j, ok = -1;
      while (ng-ok>1) {
        int mid = (ok+ng)/2;
        if (st.query(mid,j-1).val >= B[j]) {
          ok = mid;
        } else {
          ng = mid;
        }
      }
      if (ok != -1 && st.query(ok, j-1).val == B[j] && ft.query(ok,j-1) == 0) {
        found = ok;
      }
      ng = r-1, ok = n;
      while (ok-ng>1) {
        int mid = (ok+ng)/2;
        if (st.query(r,mid).val >= B[j]) {
          ok = mid;
        } else {
          ng = mid;
        }
      }
      if (ok != n && st.query(r, ok).val == B[j] && ft.query(r,ok) == 0) {
        found = ok;
      }
    }
    if (found == -1) {
      yes = false;
    } else {
      //cout << min(j,found) << " " << max(r-1,found) << " " << B[j] << "\n";
      st.range_apply(min(j,found),max(r-1,found), {true, B[j]});
    }
  }
  if (yes) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
