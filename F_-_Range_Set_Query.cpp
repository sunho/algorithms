#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct fenwick_tree {
  // [-bias, n - bias)
  fenwick_tree(int n, int bias=0) : sums(n), bias(bias) {}
  void update(int pos, ll dif) { // a[pos] += dif
    pos += bias;
    for (; pos < (int)sums.size(); pos |= pos + 1) sums[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    pos += bias;
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += sums[pos-1];
    return res;
  }
  ll query(int l, int r) { // sum of values in [l, r)
    return query(r) - query(l);
  }
  int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= (int)sums.size() && sums[pos + pw-1] < sum)
        pos += pw, sum -= sums[pos-1];
    }
    return pos-bias;
  }
private:
  vector<ll> sums;
  int bias;
};

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> C(n);
  vector<deque<int>> pos(n);
  for(int i=0;i<n;i++) {
    cin >> C[i];
    C[i]--;
    pos[C[i]].push_back(i);
  }
  vector<tuple<int,int,int>> qs(q);
  for(int i=0;i<q;i++){
    int l,r;
    cin >> l >> r;
    --l;
    qs[i] = {l,r,i};
  }
  sort(all(qs));
  fenwick_tree ft(n);
  int last_l = 0;
  vector<int> ans(q);
  for(int i=0;i<n;i++){
    if (!pos[i].empty()) {
      ft.update(*pos[i].begin(), 1);
    }
  }
  for(int i=0;i<q;i++){
    auto [l,r,k] = qs[i];
    for(int j=last_l;j<l;j++) {
      if (!pos[C[j]].empty()){
        ft.update(*pos[C[j]].begin(),-1);
        pos[C[j]].pop_front();
        if (!pos[C[j]].empty()) {
          ft.update(*pos[C[j]].begin(),1);
        }
      }
    }
    ans[k] = (int)ft.query(l,r);
    last_l = l;
  }
  for(int i=0;i<q;i++){
    cout << ans[i] << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
