#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Order statistics tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;


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

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> vals;
  for (int i=0;i<n;i++){
    cin >> A[i];
    vals.push_back(A[i]);
  }
  sort(begin(vals),end(vals));
  vals.resize(unique(begin(vals),end(vals))-begin(vals));
  int M = vals.size();
  vector<indexed_set<int>> ft(M);
  map<int,int> cvt;
  for (int j=0;j<M;j++){
    cvt[vals[j]] = j;
  }
  set<pair<int,int>> S;
  for (int i=0;i<n;i++){
    A[i] = lower_bound(begin(vals),end(vals),A[i]) - vals.begin();
    ft[A[i]].insert(i);
    S.insert({i,A[i]});
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l,r,k;
      cin >> l >> r >> k;
      --l,--r;
      if (cvt.count(k)) {
        cout << ft[cvt[k]].order_of_key(r) - ft[cvt[k]].order_of_key(l) << "\n";
      } else {
        cout << 0 << "\n";
      }
    } else {
      int l,r;
      cin >> l >> r;
      --l,--r;
      for (auto it=S.lower_bound({l,-1});it!=S.end();) {
        if (it->first > r) break;
        ft[it->second].erase(it->first);
        it = S.erase(it);
      }
    }
  }
}
