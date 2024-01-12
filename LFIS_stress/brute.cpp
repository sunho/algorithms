#include <bits/stdc++.h>
#include <queue>

using namespace std;
using ll = long long;

// Segment Tree
const ll inf = 1e18;
template <typename Info> struct seg_tree {
  int n;
  vector<Info> info;
  seg_tree(int n) : n(n), info(4 * n, Info()) {
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
  void pull(int v) { info[v] = info[v * 2] + info[v * 2 + 1]; }
  void update(int v, int l, int r, int x, const Info &val) {
    if (l == r) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    if (x <= m)
      update(v * 2, l, m, x, val);
    else
      update(v * 2 + 1, m + 1, r, x, val);
    pull(v);
  }
  void update(int x, const Info &val) { update(1, 0, n - 1, x, val); }
  Info query(int v, int l, int r, int x, int y) {
    if (l > y || r < x)
      return Info();
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    pull(v);
    return query(2 * v, l, m, x, y) + query(2 * v + 1, m + 1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n - 1, l, r); }
  int lower_bound(int v, int l, int r, int x, int y, const Info& val) {
    if (l > y || r < x)
      return n;
    if (l == r) {
      return l;
    }
    int m = (l + r) / 2;
    if (info[v*2] >= val) {
      return lower_bound(v*2, l, m, x, y, val);
    } else {
      return lower_bound(v*2+1, m+1, r, x, y, val);
    }
  }
  int lower_bound(int l, int r, const Info& val) { return lower_bound(1, 0, n - 1, l, r, val); }
};
struct node {
  pair<ll,ll> val = {inf,inf};
  friend node operator+(node lhs, node rhs) { return {min(lhs.val, rhs.val)}; }
  friend bool operator>=(node lhs, node rhs) { return lhs.val >= rhs.val; }
};

template <typename T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  pqg<tuple<ll,int,int,int>> pq;
  int cnt = 0;
  int mn = A[0];
  for (int i=0;i<n;i++) {
    if (A[i] == 0) {
      pq.push({0, i, 0, ++cnt});
    } else {
      if (i != 0) {
        pq.push({A[i]+mn, i, A[i], 2});
      }
    }
    mn = min(A[i], mn);
  }
  vector<int> id(n);
  iota(begin(id),end(id),0);
  sort(begin(id),end(id),[&](int i, int j) {
    return A[i] < A[j];
  });
  int ans = 0;
  while (!pq.empty()) {
    pqg<tuple<ll,int,int,int>> nxt;
    seg_tree<node> st(n);
    for (int i=0;i<n;i++) {
      if (A[id[i]] == 0) continue;
      while (!pq.empty() && get<0>(pq.top()) <= A[id[i]]) {
        auto [_, j, cur, dp] = pq.top();
        st.update(j, {{-dp, cur}});
        pq.pop();
      }
      auto [new_dp, prev] = st.query(0,id[i]-1).val;
      if (new_dp == inf) continue;
      new_dp *= -1;
      new_dp++;
      ans = max(ans, (int)new_dp);
      nxt.push({prev+A[id[i]], id[i], A[id[i]], new_dp});
    }
    pq = nxt;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
