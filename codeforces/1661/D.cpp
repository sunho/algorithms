#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<typename T>
struct lazy_seg_tree {
  lazy_seg_tree() = delete;
  lazy_seg_tree(int n) : n(n), d(n), t(2*n), h(sizeof(int) * 8 - __builtin_clz(n)) {
  }
  T combine(T a, T b) {
    return a+b;
  }
  void apply(int p, T value, int len) {
    t[p] += value * len;
    if (p < n) d[p] += value;
  }
  void build(int p) {
    int k = 1;
    while (p > 1) {
      p /= 2;
      k*=2;
      t[p] = combine(t[p*2], t[p*2+1]) + d[p] * k;
    }
  }
  void push(int p) {
    int k = 1 << (h-1);
    for (int s = h; s > 0; --s, k /= 2) {
      int i = p >> s;
      if (d[i] != 0) {
        apply(i*2, d[i], k);
        apply(i*2+1, d[i], k);
        d[i] = 0;
      }
    }
  }
  void inc(int l, int r, T value) {
    l += n, r += n;
    int l0 = l, r0 = r;
    int k = 1;
    for (; l < r; l /= 2, r /= 2, k *= 2) {
      if (l&1) apply(l++, value, k);
      if (r&1) apply(--r, value, k);
    }
    build(l0);
    build(r0 - 1);
  }
  // [l,r)
  T query(int l, int r) {
    T res = 0;
    l += n, r += n;
    push(l);
    push(r - 1);
    for (; l < r; l /= 2, r /= 2) {
      if (l&1) res = combine(res, t[l++]);
      if (r&1) res = combine(t[--r], res);
    }
    return res;
  }
  int n;
  vector<T> d;
  vector<T> t;
  int h;
};

void solve() {
  int n,k;
  cin >> n >> k;
  lazy_seg_tree<ll> seg(n);
  vector<ll> B(n);
  for(int i=0;i<n;i++){
    cin >> B[i];
  }
  ll ans = 0;
  for(int i=n-1;i>=0;i--){
    ll cur = seg.query(0, i+1);
    //cout << cur << "\n";
    if (cur < B[i]) {
      int l = max(i-k+1, 0);
      ll d = B[i] - cur;
      ll p = i-l+1;
      ll t = (d+p-1)/p;
      seg.inc(l, l+k, t);
      ans += t;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
