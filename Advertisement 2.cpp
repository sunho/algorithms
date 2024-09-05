#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
template<class T, T def, auto combine>
struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, def) {}
  void set(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  T get(int i) {
    return bits[i+n];
  }
  T query(int l, int r) {
    T res = def;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

ll combine_max(ll a, ll b) { return max(a,b); }
using max_seg_tree = seg_tree<ll,-inf,combine_max>;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  vector<int> X;
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    X.push_back(A[i].first);
  }
  sort(begin(X),end(X));
  X.resize(unique(begin(X),end(X))-begin(X));
  int m = (int)X.size();
  sort(begin(A),end(A),[&](auto a, auto b) {
    return a.second > b.second;
  });

  max_seg_tree st(m);
  max_seg_tree st2(m);
  int ans = 0;
  for (auto [x, a] : A) {
    int i = (int)(lower_bound(begin(X),end(X),x)-begin(X));
    if (st.query(i,m-1) >= a - x || st2.query(0,i) >= a+x) {
      continue;
    }
    ans ++;
    st.set(i,max(st.get(i),(ll)a-x));
    st2.set(i,max(st.get(i),(ll)a+x));
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
