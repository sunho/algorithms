#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, vector<pair<int,int>>> rows;
  map<int, vector<pair<int,int>>> cols;
  for (int i=0;i<n;i++){
    int x,y,a;
    cin >> x >> y >> a;
    cols[x].push_back({y,a});
    rows[y].push_back({x,a});
  }
  map<int, ll> col_sum;
  multiset<ll> avail;
  for (auto [x, vals] : cols) {
    for (auto [y,v] : vals) {
      col_sum[x] += v;
    }
    avail.insert(col_sum[x]);
  }
  ll ans = 0;
  for (auto [y, vals] : rows) {
    ll row_sum = 0;
    for (auto [x, v] : vals) {
      row_sum += v;
      avail.erase(avail.find(col_sum[x]));
      avail.insert(col_sum[x]-v);
    }
    ans = max(ans, row_sum + *--avail.end());
    for (auto [x, v] : vals) {
      avail.erase(avail.find(col_sum[x]-v));
      avail.insert(col_sum[x]);
    }
  }
  cout << ans << "\n";
}
