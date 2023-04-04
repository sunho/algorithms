#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;

struct seg_tree {
  int z;
  int n;
  vector<int> t;
  seg_tree(int n) : n(n), t(4*n, -inf) {}

  // query the combinded value on [l,r]
  int query(int l, int r, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (l > r) return -inf;
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    int x = query(l, min(r,tm), v*2, tl, tm);
    int y = query(max(tm+1,l), r, v*2+1, tm+1, tr);
    return max(x,y);
  }

  // update the node at pos
  void update(int pos, int val, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      t[v] = val;
      return;
    } 
    int tm = (tl + tr)/2;
    if (pos <= tm) {
      update(pos, val, v*2, tl, tm);
    } else {
      update(pos, val, v*2+1, tm+1,tr);
    }
    t[v] = max(t[v*2], t[v*2+1]);
  }
};

// Fenwick Tree for summation
struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l-1); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  
  vector<pair<int,int>> intervals(n);
  vector<int> A(2*n);
  vector<int> l_to_id(2*n);
  vector<int> r_to_id(2*n);
  vector<ll> ans(n);
  for (int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    --l,--r;
    intervals[i]={l,r};
    l_to_id[l] = i;
    r_to_id[r] = i;
    A[l] = i;
    A[r] = i;
  }

  vector<tuple<int,int,int>> worklist(n);
  for (int i=0;i<n;i++){
    auto [l,r] = intervals[i];
    worklist[i] = {l,r,i};
  }
  sort(begin(worklist), end(worklist), [&](auto& a, auto& b) {
    return pair<int,int>(get<1>(a), get<0>(a)) < pair<int,int>(get<1>(b), get<0>(b));
  });
  seg_tree st(2*n);
  for (auto [l,r,__] : worklist) {
    st.update(l, r);
  }
  vector<int> prd_left(n,-1);
  vector<int> prd_right(n, -1);
  for (int i=0;i<n;i++){
    auto [l,r,id] = worklist[i];
    st.update(l, -inf);
    int rr = st.query(0,r);
    if (rr != -inf) {
      prd_right[id] = r_to_id[rr];
    }
  }
  for (int i=0;i<n;i++){
    auto [l,r] = intervals[i];
    worklist[i] = {l,r,i};
  }
  sort(begin(worklist), end(worklist));
  for (auto [l,r,__] : worklist) {
    st.update(r, -l);
  }
  for (int i=n-1;i>=0;i--){
    auto [l,r,id] = worklist[i];
    st.update(r, -inf);
    int ll = st.query(l, 2*n-1);
    if (ll != -inf) {
      prd_left[id] = l_to_id[-ll];
    }
  }

  map<int,int> stack;
  ll sum = 0;
  int cnt = 0;
  for (int i=0;i<2*n;i++){
    if (!stack.count(A[i])) {
      stack[A[i]] = 1;
      ans[A[i]] += sum + cnt;
    } else {
      cnt++;
      if (prd_right[A[i]] != -1) {
        stack[prd_right[A[i]]]+=stack[A[i]];
        sum += stack[A[i]];
      }
      stack.erase(A[i]);
      if (stack.empty()) {
        sum = 0;
        cnt = 0;
      }
    }
  }
  sum=0,cnt=0;
   for (int i=2*n-1;i>=0;i--){
    if (!stack.count(A[i])) {
      stack[A[i]] = 1;
      ans[A[i]] += sum + cnt;
    } else {
      cnt++;
      if (prd_left[A[i]] != -1) {
        stack[prd_left[A[i]]]+=stack[A[i]];
        sum += stack[A[i]];
      }
      stack.erase(A[i]);
      if (stack.empty()) {
        sum = 0;
        cnt = 0;
      }
    }
  }

  fenwick_tree ft(2*n);
  for (int i=0;i<n;i++){
    auto [l,r,id] = worklist[i];
    ans[id] -= ft.query(r, 2*n-1);
    ft.update(r,1);
  }
  ft = fenwick_tree(2*n);
  for (int i=n-1;i>=0;i--){
    auto [l,r,id] = worklist[i];
    ans[id] += ft.query(0, r);
    ft.update(r,1);
  }
  ft = fenwick_tree(2*n);
  for (int i=0;i<n;i++){
    auto [l,r,id] = worklist[i];
    ft.update(l,1);
    ft.update(r,-1);
  }
  for (int i=0;i<n;i++){
    auto [l,r,id] = worklist[i];
    ans[id] += ft.query(0,r);
  }
  ft = fenwick_tree(2*n);
  for (int i=0;i<n;i++){
    auto [l,r,id] = worklist[i];
    ft.update(r,1);
    ft.update(l,-1);
  }
  for (int i=0;i<n;i++){
    auto [l,r,id] = worklist[i];
    ans[id] += ft.query(l, 2*n-1);
  }

  for (int i=0;i<n;i++){
    cout << ans[i] << "\n";
  }
}
