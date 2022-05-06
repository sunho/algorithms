#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<typename T, typename node>
struct seg_tree {
  seg_tree(int n, int bias=0) : n(n), bias(bias), a(n*4) {
  }
  seg_tree(vector<T>&v) : n((int)v.size()), bias(0), a(n*4) {
    build(0, n - 1, 1, v);
  }
  
  void build(int l, int r, int rt, vector<T>& v) {
    if(l == r) {
      a[rt].set(v[l]);
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt*2,v);
    build(m + 1, r, rt*2+1,v);
    a[rt] = a[rt*2] + a[rt*2+1];
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
    a[rt] = a[rt*2] + a[rt*2+1];
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
    if(L <= m) ret = ret + query(L, R, l, m, rt*2);
    if(m < R) ret = ret + query(L, R, m+1, r, rt*2+1);
    return ret;
  }
  T query(int L, int R) {
    L += bias, R += bias;
    return query(L, R-1, 0, n - 1, 1).value();
  }

  int n;
  int bias;
  vector<node> a;
};

const ll inf = 1e18;
struct node {
  ll val = inf;
  void set(ll v) {
    val = v;
  }
  void update(ll v) {
    val = v;
  }
  ll value() const {
    return val;
  }
  friend node operator+(const node& a, const node& b) {
    node res;
    res.val = min(a.val, b.val);
    return res;
  }
};

void solve() {
  int n,m;
  cin >> n >> m;
  seg_tree<ll, node> dp(n);
  vector<tuple<int,int,int>> reqs(m);
  for(int i=0;i<m;i++){
    int l,r,w;
    cin >> l >> r >> w;
    --l,--r;
    reqs[i] = {w,l,r};
  }
  sort(all(reqs));
  vector<vector<pair<int,int>>> ivs(n);
  for(int i=0;i<m;i++){
    auto [w,l,r] = reqs[i];
    ivs[r].emplace_back(l,w);
  }
  
  dp.update(0,0);
  for(int i=1;i<n;i++) {
    ll mini = inf;
    for(auto [l,w] : ivs[i]) {
      mini = min(dp.query(l,i+1)+w, mini);
    }
    dp.update(i,mini);
  }
  ll ans = dp.query(n-1,n);
  if (ans == inf) {
    cout << -1 << "\n";
    return;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
