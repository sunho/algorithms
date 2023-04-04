#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = (int)1e9+1;
struct SegTree {
  int n;
  vector<pair<int,int>> t;
  SegTree(int n) : n(n), t(4*n, {inf,inf}) {}
  void update(int pos, pair<int,int> val, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      t[v] = min(t[v], val);
      return;
    }
    int tm = (tl+tr)/2;
    if (pos <= tm) {
      update(pos, val, v*2, tl, tm);
    } else {
      update(pos, val, v*2+1, tm+1, tr);
    }
    t[v] = min(t[v*2], t[v*2+1]);
  }

  pair<int,int> query(int l, int r, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == l && tr == r) {
      return t[v];
    }
    if (l > r) {
      return {inf,inf};
    }
    int tm = (tl+tr)/2;
    auto a = query(l, min(r,tm), v*2, tl, tm);
    auto b = query(max(l, tm+1), r, v*2+1, tm+1, tr);
    return min(a,b);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  const int N = 1e6;
  SegTree st(N+1);

  int n,q;
  cin >> n >> q;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    st.update(A[i].first, {A[i].second, i});
  }
  vector<array<int, 32>> next(n);
  int l = ceil(log2(n));
  for (int i=0;i<l;i++){
    for (int j=0;j<n;j++){
      if (i == 0){
        auto [_, k] = st.query(A[j].second, N);
        if (k == inf) {
          next[j][i] = -1;
        } else {
          next[j][i] = k;
        }
      } else {
        next[j][i] = next[j][i-1] == -1 ? -1 : next[next[j][i-1]][i-1];
      }
    }
  }

  while (q--) {
    int a,b;
    cin >> a >> b;
    auto [e, u] = st.query(a,b);
    if (u == inf || e > b) {
      cout << 0 << "\n";
      continue;
    }
    int ans = 1;
    for (int i=l-1;i>=0;i--){
      if (next[u][i] == -1)
        continue;
      if (A[next[u][i]].second <= b) {
        u = next[u][i];
        ans += 1 << i;
      }
    }
    cout << ans << "\n";
  }

}
