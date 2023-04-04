#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

// max query
const int inf = 1e9;
struct seg_tree {
  int n;
  vector<int> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, inf) {}

  int combine(int a, int b) { return min(a,b); }
  void update(int k, int x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  int query(int l, int r) {
    int res = inf;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

void solve() {
  int n,q;
  cin >> n >> q;
  seg_tree st(n);
  for (int i=0;i<n;i++) {
    int a;
    cin >> a;
    st.update(i,a);
  }
  while (q--){
    int l,r;
    cin >> l >> r;
    --l,--r;
    cout << st.query(l, r) << "\n";
  }

}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
