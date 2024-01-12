#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  set<int> L;
  set<int> R;
  set<int> S;
  vector<int> C(n);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    L.insert(a);
    S.insert(a);
  }
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    R.insert(a);
    S.insert(a);
  }
  for (int i=0;i<n;i++){
    cin >> C[i];
  }
  sort(rbegin(C),rend(C));
  ll ans = 0;
  vector<ll> sz;
  vector<int> stk;
  for (int x : S){
    if (L.count(x)) {
        stk.push_back(x);
      } else {
        sz.push_back(x - stk.back());
        stk.pop_back();
      }
  }
  sort(begin(sz),end(sz));
  for (int i=0;i<n;i++){
    ans += (ll)(sz[i])*C[i];
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
