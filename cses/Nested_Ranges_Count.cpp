#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T> 
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n;
  cin >> n;
  vector<tuple<int,int,int>> A(n);
  indexed_set<tuple<int,int,int>> S;
  for (int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    A[i] = {a,-b,i};
  }
  sort(begin(A), end(A));
  for (int i=0;i<n;i++){
    auto [l,r,id] = A[i];
    r*=-1;
    S.insert({r,l,id});
  }
  vector<int> contains(n);
  for (int i=0;i<n;i++){
    auto [l,r,id] = A[i];
    r*=-1;
    S.erase({r,l,id});
    auto jt = S.order_of_key({r,1e9+5,n});
    contains[id] = jt;
  }
  for (int i=0;i<n;i++){
    auto [l,r,id] = A[i];
    r*=-1;
    S.insert({r,l,id});
  }
  vector<int> contained(n);
  for (int i=n-1;i>=0;i--){
    auto [l,r,id] = A[i];
    r*=-1;
    S.erase({r,l,id});
    auto jt = S.order_of_key({r,0,0});
    contained[id] = S.size() - jt;
  }
  for (int i=0;i<n;i++){
    cout << contains[i] << " ";
  }
  cout << "\n";
  for (int i=0;i<n;i++){
    cout << contained[i] << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
