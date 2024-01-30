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

ll combine_min(ll a, ll b) { return min(a,b); }
using min_seg_tree = seg_tree<ll,inf,combine_min>;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  ll sum = accumulate(begin(A),end(A),0ll);
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  ll ng = 0, ok = sum+1;
  auto check = [&](ll cost) {
    vector<ll> dp(n+2);
    max_seg_tree dp2(n+2);
    dp[0] = 0;
    dp2.set(0,0);
    for (int i=1;i<=n+1;i++){
      int k = ranges::lower_bound(pf,pf[i-1]-cost)-begin(pf);
      if (k <= i-1) {
        dp[i] = max(dp[i], pf[i-1] + dp2.query(k, max(i-1,0)));
      }
      dp[i] = max(dp[i], dp[i-1]);
      if (i != n+1)
        dp2.set(i, dp[i]-pf[i]);
    }
    return sum - dp[n+1] <= cost;
  };
  while (ok - ng > 1) {
    ll mid = (ok + ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
