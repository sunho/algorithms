#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> A(n);
  indexed_set<pair<int,int>> S;
  for(int i=0;i<n;i++) cin >> A[i];
  for (int i=0;i<n;i++) {
    S.insert({A[i],i});
  }
  while (q--){
    char c;
    cin >> c; 
    if (c == '!') {
      int i,t;
      cin >> i >> t;
      --i; 
      S.erase({A[i],i});
      A[i] = t;
      S.insert({A[i],i});
    } else {
      int a,b;
      cin >> a >> b;
      cout << S.order_of_key({b,n}) - S.order_of_key({a,0}) << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
