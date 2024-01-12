#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// max query
const int inf = 1e9;
struct seg_tree {
  int n;
  vector<int> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, 0) {}

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
  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector val = A;
  for (int a : A) {
    val.push_back(a-x);
  }
  sort(begin(val),end(val));
  val.resize(unique(begin(val),end(val))-begin(val));
  int m = val.size();
  for (int i=0;i<n;i++){
    A[i] = lower_bound(begin(val),end(val),A[i])-begin(val);
  }
  vector<seg_tree> dp(2, seg_tree(m));
  for (int i=0;i<n;i++){
    int nx = lower_bound(begin(val),end(val),val[A[i]] - x) - begin(val);
    int new_z = max(dp[0].query(nx, nx), max(dp[0].query(0,nx-1),0)+1);
    int new_zz = max(dp[1].query(A[i], A[i]), max({dp[0].query(0,A[i]-1), dp[1].query(0,A[i]-1),0})+1);
    dp[0].update(nx, new_z);
    dp[1].update(A[i], new_zz);
  }
  cout << dp[1].query(0,m-1) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
