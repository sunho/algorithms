#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct mo_query {
  int n;
  vector<pair<int, int>> lr;

  explicit mo_query(int n) : n(n) {}

  void add(int l, int r) { /* [l, r) */
    lr.emplace_back(l, r);
  }

  template< typename AL, typename AR, typename EL, typename ER, typename O >
  void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
    int q = (int) lr.size();
    int bs = n / min< int >(n, sqrt(q));
    vector< int > ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
      if(ablock != bblock) return ablock < bblock;
      return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
    });
    int l = 0, r = 0;
    for(auto idx : ord) {
      while(l > lr[idx].first) add_left(--l);
      while(r < lr[idx].second) add_right(r++);
      while(l < lr[idx].first) erase_left(l++);
      while(r > lr[idx].second) erase_right(--r);
      out(idx);
    }
  }

  template< typename A, typename E, typename O >
  void build(const A &add, const E &erase, const O &out) {
    build(add, add, erase, erase, out);
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(n+1);
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  int q;
  cin >> q;
  mo_query mo(q);
  vector<int> qx(q);
  vector<int> ans(q);
  for(int i=0;i<q;i++){
    int l,r,x;
    cin >> l >> r >> x;
    --l,--r;
    mo.add(l,r+1);
    qx[i] = x;
  }
  auto add = [&](int i) {
    cnt[A[i]]++;
  };
  auto remove = [&](int i) {
    cnt[A[i]]--;
  };
  auto output = [&](int i) {
    ans[i] = cnt[qx[i]];
  };
  mo.build(add,remove,output);
  for(int i=0;i<q;i++){
    cout << ans[i] << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
