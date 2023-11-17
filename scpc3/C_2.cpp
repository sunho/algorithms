#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;
struct seg_tree {
  int n;
  vector<int> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, -inf) {}

  int combine(int a, int b) { return max(a,b); }
  void update(int k, int x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  int query(int l, int r) {
    int res = -inf;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  if (n > 1000) {
    cout << 0 << "\n";
    return;
  }
  vector<int> A(n);
  vector<int> pos;
  pos.push_back(-1);
  for (int i=0;i<n;i++) {
    cin >> A[i];
    if (A[i] == 2) {
      pos.push_back(i);
    }
  }
  pos.push_back(n);
  int m, t;
  cin >> m >> t;
  seg_tree dp(n);
  while (m--) {
    seg_tree nxt = dp;
    vector<int> pf(n+1, -inf);
    pf[0] = 0;
    for (int i=0;i<n;i++) {
      pf[i+1] = max(pf[i], dp.query(i,i)+i);
      int x = *--lower_bound(begin(pos),end(pos), i);
      int y = *upper_bound(begin(pos),end(pos), i);
      int mn = min(i-x-1,t);
      int dy = min(y-i-1,t);
      int dy2 = min(y-i,t);
      int cand = 1+mn+dy;
      if (i-mn-1>=0) {
        cand += pf[i-mn-1];
      }
      if (i-x<=t && x >= 0) {
        cand = max(cand, dp.query(x, x) + x + 2 + mn + dy);
        //cout << "cand: " << cand << "\n";
      }
      if (i != 0) {
        cand = max(cand, dp.query(max(i-mn-1,0), i-1) + i + dy);
        /* cout << i << " " << "cand: " << cand << "\n"; */
      }
      int nx = min(i+dy2,n-1);
      cand -= nx;
      nxt.update(nx, max(nxt.query(nx,nx), cand));
    }
    /* for (int i=0;i<n;i++){ */
    /*   cout << nxt.query(i, i) + i << " "; */
    /* } */
    /* cout << "\n"; */
    dp = nxt;
  }
  int ans = -inf;
  for (int i=0;i<n;i++) {
    ans = max(ans, dp.query(i,i) + i);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t=0;t<T;t++){
    cout << "Case #" << t+1 << "\n";
    solve();
  }
}
