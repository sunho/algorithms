#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int cnt(vector<int> a) {
  int n = a.size();
  int N = 1 << n;
  int res = 0;
  for (int msk = 1; msk < N; msk++) {
    vector<int> b;
    set<int> S;
    for (int i=0;i<n;i++){
      if (msk >> i &1) {
        b.push_back(a[i]);
        S.insert(a[i]);
      }
    }
    if (S.size() != __builtin_popcount(msk)) continue;
    if (!is_sorted(begin(b),end(b))) continue;
    res ++;
  }
  return res+1;
}

void solve() {
  ll x;
  cin >> x;
  int pp = 0;
  vector<int> ans;
  bool done = false;
  for (int i=63;i>0;i--) {
    if (!(x >> i & 1)) continue;
    if (!done) {
      done = true;
      for (int j=0;j<i;j++){
        ans.push_back(j+1);
      }
    } else {
      ans.push_back(i+1);
      //pp++;
    }
  }
  if (x&1) pp ++;
  for (int i=0;i<pp;i++){
    ans.push_back(-(i+1));
  }
  //assert (cnt(ans) == x);
  cout << ans.size() << "\n";
  for (int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
