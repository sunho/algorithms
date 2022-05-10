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
    if (L == R) return node().value();
    L += bias, R += bias;
    return query(L, R-1, 0, n - 1, 1).value();
  }

  int n;
  int bias;
  vector<node> a;
};

const int inf = 1e9+10;
struct node {
  int val = -inf;
  void set(int v) {
    val = v;
  }
  void update(int v) {
    val = v;
  }
  int value() const {
    return val;
  }
  friend node operator+(const node& a, const node& b) {
    node res;
    res.val = max(a.val, b.val);
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  sort(all(A));
  vector<pair<int,int>> p(n);
  vector<pair<int,int>> p2(n);
  for(int i=0;i<n;i++){
    p[i] = {A[i].first - A[i].second,i};
    p2[i] = {A[i].first + A[i].second,i};
  }
  auto srt_p = p;
  auto srt_p2 = p2;
  sort(all(srt_p));
  sort(all(srt_p2));
  vector<int> id(n);
  vector<int> id2(n);
  for(int i=0;i<n;i++){
    id[i] = lb(srt_p,p[i]);
    id2[i] = lb(srt_p2,p2[i]);
  }
  vector<seg_tree<int, node>> stX(2, seg_tree<int, node>(n));
  vector<seg_tree<int, node>> stY(2, seg_tree<int, node>(n));
  for(int i=0;i<n;i++){
    stX[0].update(id[i], A[i].first);
    stY[0].update(id[i], A[i].second);
    stX[1].update(id2[i], A[i].first);
    stY[1].update(id2[i], -A[i].second);
  }

  int h = 0;
  for(int i=0;i<n;i++){
    auto [x,y] = A[i];
    stX[0].update(id[i], -inf);
    stY[0].update(id[i], -inf);
    stX[1].update(id2[i], -inf);
    stY[1].update(id2[i], -inf);
    ckmax(h, stX[0].query(0,id[i]+1) - x);
    ckmax(h, stY[0].query(id[i],n) - y);
    ckmax(h, stX[1].query(0,id2[i]+1) - x);
    ckmax(h, y + stY[1].query(id2[i],n));
  }
  cout << h << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
