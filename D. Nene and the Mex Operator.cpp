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
  const int N = 18;
  vector<vector<pair<int,int>>> ops(N+1);
  for (int i=1;i<=N;i++){
    for (int j=1;j<i;j++) {
      for (auto x : ops[j]) {
        ops[i].push_back(x);
      }
    }
    ops[i].push_back({0,i-1});
  }
  vector<pair<int,int>> ans;
  auto f = [&](auto&& self, int l, int r) {
    if (l > r) return;
    vector<int> ban(n);
    int m = (r-l+1);
    for (int i=l;i<=r;i++){
      if (A[i] > m) {
        ban[i] = true;
      }
    }
    int last = l;
    for (int i=l;i<=r;i++){
      if (ban[i]) {
        self(self, last, i-1);
        last = i+1;
      }
    }
    if (last == l) {
      bool ok = false;
      for (int i=l;i<=r;i++){
        if (A[i] != 0) 
          ok = true;
      }
      if (ok) {
        ans.push_back({l,r});
        ans.push_back({l,r});
      }
      for (auto [x,y] : ops[m]) {
        ans.push_back({l+x, r+y});
      }
      for (int i=l;i<=r;i++){
        A[i] = m;
      }
    } else if (last <= r) {
      self(self, last, r);
    }
  };
  f(f,0,n-1);
  ll sum = 0;
  for( int i=0;i<n;i++){
    sum += A[i];
  }
  cout << sum << " " << ans.size() << "\n";
  for (auto [l,r] : ans) {
     cout << l + 1 << " " << r+1 << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
