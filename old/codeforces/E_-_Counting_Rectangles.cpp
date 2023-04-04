#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// trimmed version
struct fenwick_tree {
  // [-bias, n - bias)
  fenwick_tree(int n) : sums(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < (int)sums.size(); pos |= pos + 1) sums[pos] += dif;
  }
  __int128 query(int pos) { // sum of values in [0, pos)
    __int128 res = 0;
    for (; pos > 0; pos &= pos - 1) res += sums[pos-1];
    return res;
  }
  __int128 query(int l, int r) { // sum of values in [l, r)
    return query(r) - query(l);
  }
private:
  vector<__int128> sums;
};

void solve() {
  int q,n;
  cin >> n >> q;
  deque<pair<int,int>> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i].first >> A[i].second;
  }
  vector<pair<pair<int,int>,pair<int,int>>> queries(q);
  for (int i=0;i<q;i++) {
    pair<int,int> mini;
    pair<int,int> maxi;
    cin >> mini.first >> mini.second >> maxi.first >> maxi.second;
    queries[i] = {mini,maxi};
  }
  vector<pair<int,int>> process;
  process.reserve(4*q);
  for(auto& query : queries) {
    process.push_back({query.first.first+1, query.first.second+1});
    process.push_back({query.first.first+1, query.second.second});
    process.push_back({query.second.first, query.first.second+1});
    process.push_back(query.second);
  }
  sort(all(process));
  sort(all(A));
  map<pair<int,int>, ll> cache;

  fenwick_tree FT(1002);
  deque<pair<int,int>> que = A;
  for (auto& query : process) {
    auto [h, w] = query;
    while (!que.empty() && que.front().first < h) {
      auto [hh, ww] = que.front();
      FT.update(ww, (ll)hh*ww);
      que.pop_front();
    }
    cache[{h,w}] = FT.query(w);
  }
  for (int i=0;i<q;i++) {
    auto [hmin, wmin] = queries[i].first;
    auto [hmax, wmax] = queries[i].second;
    cout << cache[{hmax, wmax}] - cache[{hmax, wmin+1}] - cache[{hmin+1, wmax}] + cache[{hmin+1, wmin+1}] << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
