#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
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
    int bs = n / min< int >(n, (int)sqrt(q));
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
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
    --A[i];
  }
  int q;
  cin >> q;
  vector<list<int>> pos(k);
  vector<int> max_len(n+1);
  int bs = min((int)sqrt(n+1)+1,n+1);
  int bn = (n+1+bs-1) / bs;
  vector<int> lens_block(bn);
  mo_query mo(q);
  vector<int> ans(q);
  for(int i=0;i<q;i++) {
    int a,b;
    cin >> a >> b;
    --a;
    mo.add(a,b);  
  }
  auto len = [&](int i) {
     return pos[A[i]].empty() ? 0 : (*--pos[A[i]].end() - *pos[A[i]].begin()+1);
  };
  auto update_len = [&](int prev, int next) {
    if (next != 0) {
      max_len[next]++;
      lens_block[next/bs]++;
    }
    if (prev != 0) {
      max_len[prev]--;
      lens_block[prev/bs]--;
    }
  };
  auto add_left = [&](int i) {
    int prev = len(i);
    pos[A[i]].push_front(i);
    int next = len(i);
    update_len(prev, next);
  };
  auto add_right = [&](int i) {
    int prev = len(i);
    pos[A[i]].push_back(i);
    int next = len(i);
    update_len(prev, next);
  };
  auto remove_left = [&](int i) {
    int prev = len(i);
    pos[A[i]].pop_front();
    int next = len(i);
    update_len(prev, next);
  };
  auto remove_right = [&](int i) {
    int prev = len(i);
    pos[A[i]].pop_back();
    int next = len(i);
    update_len(prev, next);
  };
  auto out = [&](int i) {
    int last = 0;
    for(int i=0;i<bn;i++){
      if (lens_block[i] > 0) last = i;
    }
    int cur_max_len = 0;
    for(int i=bs*last;i<bs*(last+1) && i <= n;i++) {
      if (max_len[i] > 0) ckmax(cur_max_len, i);
    }
    ans[i] = cur_max_len;
  };
  mo.build(add_left, add_right, remove_left, remove_right, out);
  for(int i=0;i<q;i++){
    cout << ans[i]-1 << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
