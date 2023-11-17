#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
struct seg_tree {
  int n;
  vector<ll> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, inf) {}

  ll combine(ll a, ll b) { return min(a,b); }
  void update(int k, ll x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  ll query(int l, int r) {
    ll res = inf;
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
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i].first >> A[i].second;
  }
  int q;
  cin >> q;
  vector<pair<int,int>> queries(q);
  for (int i=0;i<q;i++){
    cin >> queries[i].first >> queries[i].second;
    queries[i].first --, queries[i].second --;
  }
  seg_tree st(n);

  vector<tuple<int,int,ll>> updates;
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      ll area = (ll)(A[i].second+A[j].second)*(A[j].first - A[i].first);
      updates.push_back({i,j,area});
    }
  }

  vector<int> id(q);
  iota(begin(id), end(id), 0);
  sort(begin(id),end(id),[&](int i,int j) {
    return queries[i] < queries[j];
  });
  sort(begin(queries),end(queries));
  vector<ll> ans(q);
  int left=updates.size()-1;
  for (int i=q-1;i>=0;i--) {
    auto [l,r] = queries[i];
    while (left>=0 && get<0>(updates[left])>=l) {
      auto [x,y,k] = updates[left];
      st.update(y,min(st.query(y,y),k));
      left--;
    }
    ans[id[i]] = st.query(0,r);
  }
  for (int i=0;i<q;i++) {
    cout << ans[i] << "\n";
  }
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
