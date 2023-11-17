#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l-1); }
};

const int MOD = 998244353;
struct mint {
  int x;
  mint() : x(0) {}
  mint(ll val) : x(val % MOD) { x += (x < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.x += b.x) >= MOD) a.x -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.x -= b.x) < 0) a.x += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.x * b.x); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

const int NN = 1e6;
mint facts[NN];

mint choose(int n, int k) {
  return facts[n]/(facts[k]*facts[n-k]);
}

int main() {

  facts[0] = 1;
  for (int i=1;i<NN;i++){
    facts[i] = facts[i-1]*i;
  }

  int n, k;
  cin >> n >> k;

  vector<int> values;
  vector<pair<int,int>> intervals;
  
  for (int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    values.push_back(l);
    values.push_back(r);
    intervals.push_back({l,r});
  }
  sort(begin(values),end(values));
  values.resize(unique(begin(values),end(values))-begin(values));
  int N = values.size() + 10;
  vector<vector<int>> starts(N);
  for (int i=0;i<n;i++){
    intervals[i].first = lower_bound(begin(values),end(values),intervals[i].first) - begin(values);
    intervals[i].second = lower_bound(begin(values),end(values),intervals[i].second) - begin(values);
    starts[intervals[i].first].push_back(intervals[i].second);
  }
  sort(begin(intervals),end(intervals));
  int num = 0;
  map<int,int> cnt;
  mint ans = 0;
  for (int i=0;i<N;i++) {
    for (auto x : starts[i]) {
      cnt[x]++;
      num++;
    }
    if (cnt.count(i)) {
      for (int z=0;z<cnt[i];z++){
        num--;
        if (num >= k-1) {
          ans += choose(num,k-1);
        }
      }
    }
  }
  cout << ans.x << "\n";
}
