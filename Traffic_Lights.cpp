#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  set<pair<int,int>> S;
  multiset<int> sz;
  S.insert({0,n});
  sz.insert(n);
  for (int i=0;i<m;i++){
    int t;
    cin >> t;
    auto it = --S.upper_bound({t,0});
    auto [x,y] = *it;
    sz.erase(sz.find(y-x));
    S.erase(it );
    pair<int,int> L = {x, t};
    pair<int,int> R = {t, y};
    S.insert(L);
    sz.insert(L.second - L.first);
    S.insert(R);
    sz.insert(R.second - R.first);
    cout << *(--sz.end()) << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
