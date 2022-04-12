#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct seg_tree {
  seg_tree(int n) : n(n), a(n*4) {
    build(0, n - 1, 1);
  }
  struct node {
    ll sum = 0;
    void update(ll v) {
      sum += v;
    }
  };
  node merge(const node &x, const node &y) {
    node ret;
    ret.sum = x.sum + y.sum;
    return ret;
  }
  void build(int l, int r, int rt) {
    if(l == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt*2);
    build(m + 1, r, rt*2+1);
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
  node query(int L, int R) {
    return query(L, R-1, 0, n - 1, 1);
  }

  int n;
  vector<node> a;
};

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll cnt = 0;

  auto mod = [&](ll x, int m) {
    return ((x % m) + m) %m;
  };
  vector<seg_tree> ft(3, seg_tree(2*n+1));
  vector<int> S(n+1);
  for(int i=0;i<n;i++) {
      S[i+1] = S[i];
      if (s[i] == '-') S[i+1]++;
      else S[i+1]--;
  }

  // S[r+1] = S[l] (mod 3) and (S[r+1] >= S[l])
  for(int i=0;i<=n;i++){
      cnt += ft[mod(S[i],3)].query(0, S[i] + 1 + n).sum;
      ft[mod(S[i],3)].update(S[i] + n, 1);
  }
  cout << cnt << "\n";
}
 
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--){
    solve();
  }

  return 0;
}
