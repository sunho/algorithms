#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fenwick Tree for summation
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
      if ((pos+pw) <= n && sum > bits[pos+pw]) {
        sum -= bits[pos+pw], pos += pw;
      }
    }
    return pos;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  FenwickTree ft(n);
  for (int i=0;i<n;i++){
    ft.update(i,1);
  }
  for (int i=0;i<n;i++){
    int j;
    cin >> j;
    int k = ft.lower_bound(j);
    cout << A[k] << " ";
    ft.update(k, -1);
    // cout << k << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
