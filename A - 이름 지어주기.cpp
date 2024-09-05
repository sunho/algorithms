#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  int a,b;
  cin >> a >> b;
  pair<int,int> ans = {0,0};
  auto go = [&](int x) {
    if (x % 2 == 1 && a <= x && x <= b) {
      int res = (int)1e9+10;
      for (int i=0;i<n;i++){
        res = min(res, abs(A[i]-x));
      }
      ans = max(ans, {res, x});
    }
  };
  go(a);
  go(a+1);
  go(b-1);
  go(b);
  for (int i=0;i<n-1;i++){
    int x = (A[i]+A[i+1])/2;
    go(x-1);
    go(x);
    go(x+1);
  }
  cout << ans.second << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
