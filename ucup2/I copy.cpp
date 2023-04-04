#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

#define dbg(x) "(" << #x <<": " << (x) << ") "
template<typename Ostream, typename Cont>
enable_if_t<is_same_v<Ostream,ostream>, Ostream&> 
operator<<(Ostream& os, const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename ...Ts>
ostream& operator<<(ostream& os, const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

 // Fenwick Tree for summation
struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}

  // add delta to node v
  void update(int v, int delta) {
    for (++v; v <= n; v += v&(-v)) 
      bits[v] += delta;
  }

  // get prefix sum of range [0,r]
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r))
      res += bits[r];
    return res;
  }
  ll query(int l, int r) {
    return query(r) - query(l-1);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  fenwick_tree ft(n*5+10);
  vector<tuple<int,int,int>> intervals(n);
  for (int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    ft.update(r, 1);
    r*=-1;
    intervals[i] = {l,r,i};
  }
  auto query = [&](int ll, int rr) {
    int cnt = 0;
    for (int i=0;i<n;i++){
      auto [l,r,_] = intervals[i];
      r*=-1;
      if(max(ll,l) <= min(r,rr)) cnt++;
    }
    return cnt;
  };
  
  sort(begin(intervals), end(intervals));
  set<tuple<int,int,int>> S;
  vector adj(n, vector<int>());
  for (int i=0;i<n;i++){
    auto [l,r,j] = intervals[i];
    r*=-1;
    S.insert({r,l,i});
  }
  vector<int> prd(n, -1);
  vector<tuple<int,int,int>> reduced;
  for (int i=n-1;i>=0;i--){
    auto [l,r,id] = intervals[i];
    r*=-1;
    S.erase({r,l,i});
    auto jt = S.lower_bound({r,0,0});
    if (jt != S.end()) {
      auto [rr,ll,u] = *jt;
      adj[u].push_back(i);
      prd[i] = u;
    }
  }

  for (int i=0;i<n;i++) {
    if (prd[i] == -1) {
      auto [l,r,_] = intervals[i];
      r *= -1;
      reduced.push_back({l,r,i});
      cout << l << " " << r << "\n";
    }
  }
  sort(begin(reduced), end(reduced));

  vector<ll> ans(n);
  vector<int> vis(n);
  auto dfs = [&](auto self, int u, int cnt_cur, ll sum) -> void {
    vis[u] = true;
    for (int v : adj[u]) {
      if (!vis[v])
        self(self, v, cnt_cur, sum);
    }
    auto [l,r,_] = intervals[u];
    r*=-1;
    int q = ft.query(l,r);
    ans[get<2>(intervals[u])] = (cnt_cur-q)*2 + q + sum;
  };
  
  int right = 0;
  while (right < reduced.size()) {
    int left = right;
    pair<int,int> last = {get<0>(reduced[right]), get<1>(reduced[right])};
    int ml=last.first,mr=last.second;
    right++;
    while (right < reduced.size()){
      pair<int,int> cur = {get<0>(reduced[right]), get<1>(reduced[right])};
      if (last.second >= cur.first) {
        last = cur;
        ml = min(ml, last.first);
        mr = max(mr, last.second);
      } else {
        break;
      }
      right++;
    }
    vector<ll> sum_left(n);
    vector<ll> sum_right(n);
    vector<int> cnt_left(n);
    vector<int> cnt_right(n);
    for (int i=right-1;i>=left;i--) {
      auto [l,r,_] = reduced[i];
      cnt_right[i] = query(l, mr) - query(l,r);
      cout << dbg(query(l, mr)) dbg( query(l,r)) << "\n";
      sum_right[i] += cnt_right[i];
      if (i != right-1) {
        sum_right[i] += cnt_right[i+1];
        sum_right[i] += sum_right[i+1];
      }
    }
    for (int i=left;i<right;i++) {
      auto [l,r,_] = reduced[i];
      cnt_left[i] = query(ml, r) - query(l,r);
      if (i != left) {
        sum_left[i] += sum_left[i-1];
        sum_left[i] += cnt_left[i-1];
      }
    }
    cout << dbg(sum_left) dbg(sum_right) dbg(cnt_left) dbg(cnt_right) << "\n";
    for (int i=left;i<right;i++) {
      auto [l,r,_] = reduced[i];
      int cntt =  query(l,r);
      dfs(dfs, i, cntt, sum_left[i] + sum_right[i] - cntt);
    }
  }
  
  for (ll d : ans) {
    cout << d << "\n";
  }

}
