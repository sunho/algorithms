#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  void update_range(int l, int r, int delta) { 
    update(l, delta);
    update(r+1, -delta);
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> inv(n+1);
  for (int i=0;i<n;i++){
    cin >> A[i];
    inv[A[i]] = i;
  }

  stack<pair<int,int>> stk;
  vector<int> s(n), m(n), l2(n);
  for (int i=0;i<n;i++){
    while (!stk.empty() && stk.top().second < A[i]) {
      stk.pop();
    }
    if (stk.empty()) {
      s[i] = -1;
    } else {
      s[i] = stk.top().first;
    }
    stk.push({i, A[i]});
  }
  while(!stk.empty()) {
    stk.pop();
  }
  for (int i=n-1;i>=0;i--){
    while (!stk.empty() && stk.top().second < A[i]) {
      stk.pop();
    }
    if (stk.empty()) {
      l2[i] = n;
    } else {
      l2[i] = stk.top().first;
    }
    stk.push({i, A[i]});
  }
  seg_tree st(n);
  for (int i=1;i<=n;i++){
    if (l2[inv[i]] == n) {
      m[inv[i]] = n;
    } else {
      int res = st.query(l2[inv[i]], n-1);
      if (res == inf) {
        m[inv[i]] = n;
      } else {
        m[inv[i]] = res;
      }
    }
    st.update(inv[i],inv[i]);
  }
  vector<tuple<int,int,int,int>> pts;
  for (int i=0;i<n;i++){
    int x1 = s[i]+1, x2 = i;
    int y1 = l2[i], y2 = m[i]-1;
    //cout << x1 << " " << x2 << " " << y1 << " " << y2 << "\n";
    if (x1 > x2) continue;
    if (y1 > y2) continue;
    pts.push_back({x1,x2,y1,y2});
  }
  sort(begin(pts),end(pts));

  fenwick_tree ft(n+1);
  int q;
  cin >> q;
  vector<pair<int,int>> query;
  for (int i=0;i<q;i++){
    int l,r;
    cin >> l >> r;
    --l,--r;
    query.push_back({l,r});
  }
  vector<int> ans(q);
  vector<int> id(q);
  iota(begin(id),end(id),0);
  sort(begin(id),end(id),[&](int i, int j) {
    return query[i] < query[j];
  });
  sort(begin(query),end(query));
  int cur = 0;
  multiset<tuple<int,int,int>> exits;
  for (int i=0;i<q;i++){
    auto [x,y] = query[i];
    while (cur < pts.size() && get<0>(pts[cur]) <= x) {
      auto [x1,x2,y1,y2] = pts[cur];
      ft.update_range(y1,y2,1);
      exits.insert({x2,y1,y2});
      cur++;
    }
    while (!exits.empty() && get<0>(*exits.begin()) < x) {
      auto [x2, y1, y2] = *exits.begin();
      ft.update_range(y1,y2,-1);
      exits.erase(exits.begin());
    }
    if (ft.query(y)) {
      ans[id[i]] = 1;
    }
  }
  for (int i=0;i<q;i++){
    if (ans[i]) {
      cout << "Yes" << "\n";
    } else {
      cout << "No" << "\n";
    }
  }
}
