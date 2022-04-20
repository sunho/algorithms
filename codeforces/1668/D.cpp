#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
const int inf = 1e9;
struct seg_tree {
  seg_tree(int n, int bias=0) : n(n), bias(bias), a(n*4) {
  }
  seg_tree(vector<int>&v) : n(v.size()), bias(0), a(n*4) {
    build(0, n - 1, 1, v);
  }
  struct node {
    ll sum = -inf;
    void update(ll v) {
      sum = max(v,sum);
    }
  };
  node merge(const node &x, const node &y) {
    node ret;
    ret.sum = max(x.sum, y.sum);
    return ret;
  }
  void build(int l, int r, int rt, vector<int>& v) {
    if(l == r) {
      a[rt].sum = v[l];
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt*2,v);
    build(m + 1, r, rt*2+1,v);
    a[rt] = merge(a[rt*2], a[rt*2+1]);
  }
  template <typename... V>
  void update(int pos, int l, int r, int rt, const V&... v) {
    if(l == r) {
      a[rt].update(v...);
      return;
    }
    int m = (l + r) / 2;
    if(pos <= m) update(pos, l, m, rt*2, v...);
    else update(pos, m+1, r, rt*2+1, v...);
    a[rt] = merge(a[rt*2], a[rt*2+1]);
  }
  template <typename... V>
  void update(int pos, const V&... v) {
    pos += bias;
    update(pos, 0, n - 1, 1, v...);
  }
  node query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return a[rt];
    node ret;
    int m = (l + r) / 2;
    if(L <= m) ret = merge(ret, query(L, R, l, m, rt*2));
    if(m < R) ret = merge(ret, query(L, R, m+1, r, rt*2+1));
    return ret;
  }
  ll query(int L, int R) {
    if (L == R) return node().sum;
    L += bias, R += bias;
    return query(L, R-1, 0, n - 1, 1).sum;
  }

  int n;
  int bias;
  vector<node> a;
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<ll> pf(n+1);
  for(int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  auto s_pf = pf;
  sort(all(s_pf));
  s_pf.resize(unique(all(s_pf)) - s_pf.begin());
  auto id = pf;
  for(int i=0;i<n+1;i++) {
    id[i] = lower_bound(all(s_pf), pf[i]) - s_pf.begin();
  }
  vector<ll> dp(n+1);
  seg_tree seg(n+1);
  for(int i=0;i<n;i++) {
    dp[i+1] = dp[i];
    if (A[i] < 0) dp[i+1]--;
    else if (A[i] > 0) dp[i+1]++;
    ll k = seg.query(0, id[i+1]);
    ckmax(dp[i+1], k + i + 1);
    if (pf[i+1] > 0) dp[i+1] = i + 1;
    seg.update(id[i+1], dp[i+1] - i - 1);
  }
  cout << dp[n] << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
