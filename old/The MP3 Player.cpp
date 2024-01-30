#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// generic seg tree
template <class T> struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n+1)*2) {
    for (int i = n - 1; i > 0; --i) 
      bits[i] = bits[i<<1] + bits[i<<1|1];
  }

  void update(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = bits[k*2] + bits[k*2+1];
  }
  T query(int l, int r) {
    T resl = {}, resr = {};
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) resl = resl + bits[l++];
      if (!(r & 1)) resr = bits[r--] + resr;
    }
    return resl + resr;
  }
};
int mx;
struct node {
  int l=0,r=mx,f=0;
  node() = default;
  friend node operator+(node lhs, node rhs) {
    int l1 = lhs.l, r1 = lhs.r, f1 = lhs.f;
    int l2 = rhs.l, r2 = rhs.r, f2 = rhs.f;
    int l3 = l1+l2-f1;
    int r3 = r2+l1-f1;
    int f3 = f2;
    if (l3 >= r1) {
      return {mx,mx,f2};
    }
    if (l3 <= l1) {
      f3 = f2 + clamp(f1-l2,0,r2-l2);
      l3 = l1;
    }
    if (r3 <= l1) {
      return {mx,mx,f3};
    }
    if (r3 >= r1) {
      r3 = r1;
    }
    return {l3,r3,f3};
  }
  int eval(int x) {
    return f + clamp(x-l,0,r-l);
  }
};


void solve() {
  int n, v2;
  cin >> n >> mx >> v2;
  node plus = {0,mx-1,1};
  node minus = {1,mx,0};
  seg_tree<node> st(n+1);
  vector<pair<char,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  vector<pair<int,int>> B;
  for (int i=0;i<n-1;i++){
    B.push_back({A[i+1].second-A[i].second,i+1});
  }
  B.push_back({A[0].second,0});
  sort(begin(B),end(B));
  pair<int,int> ans = {0,v2};
  auto check = [&]() {
    auto ff = st.query(0,n);
    if (ff.f > v2) 
      return -1;
    if (ff.f == v2) {
      return ff.l;
    }
    int lim = ff.f + ff.r - ff.l;
    if (v2 > lim)  {
      return -1;
    }
    if (v2 == lim) {
      return mx;
    }
    return v2 - ff.f + ff.l;
  };
  int ptr = 0;
  for (int i=0;i<n;i++) {
    while (ptr < n && B[ptr].first < B[i].first) {
      int j = B[ptr].second;
      if (j != 0) {
        if (A[j].first == '+') {
          st.update(j, plus);
        } else if (A[j].first == '-'){
          st.update(j, minus);
        }
      }
      ptr++;
    }
    int cand = check();
    if (cand != -1) {
      ans = max(ans,{B[i].first-1,cand});
    }
  }
  while (ptr < n) {
    int j = B[ptr].second;
    if (j != 0) {
      if (A[j].first == '+') {
        st.update(j, plus);
      } else if (A[j].first == '-'){
        st.update(j, minus);
      }
    }
    ptr++;
  }
  if (check() != -1) {
    cout << "infinity" << "\n";
  } else {
    cout << ans.first << " " << ans.second << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
