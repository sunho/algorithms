#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FenwickTree {
  int n;
  vector<ll> bits;
  FenwickTree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) {
    for (++v; v <= n; v += v&(-v)) 
      bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r))
      res += bits[r];
    return res;
  }
  ll query(int l, int r) {
    return query(r) - query(l-1);
  }
  int lower_bound(ll sum) {
    int pos = 0;
    for (int pw = 1<<30; pw; pw >>= 1) {
      if ((pos+pw) <= n && sum >= bits[pos+pw]) {
        sum -= bits[pos+pw], pos += pw;
      }
    }
    return pos;
  }
};

void solve() {
  int n;
  cin >> n;
  int k = 1;
  FenwickTree ft(n);
  for (int i=0;i<n;i++)
    ft.update(i, 1);
  int cur = 0;
  vector<int> ans;
  for (int i=0;i<n;i++){
    int m = n-i;
    cur += k;
    cur %= m;
    int j = ft.lower_bound(cur);
    ans.push_back(j);
    ft.update(j, -1);
  }
  for (int i=0;i<n;i++){
    cout << ans[i] + 1 << " ";
  }

}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
