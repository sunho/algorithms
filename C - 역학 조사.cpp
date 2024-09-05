#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(m);
  vector<vector<int>> inv(n);
  for (int i=0;i<m;i++){
    int k;
    cin >> k;
    for (int j=0;j<k;j++){
      int a;
      cin >> a;
      --a;
      A[i].push_back(a);
      inv[a].push_back(i);
    }
  }
  vector<int> B(n);
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  auto B3 = B;
  vector<int> f(n, -1);
  for (int i=m-1;i>=0;i--){
    bool tt = false;
    for (int a : A[i]) {
      if (!B3[a]) {
        tt = true;
      }
    }
    for (int a : A[i]) {
      if (tt) {
        f[a] = max(f[a],i+1);
        B3[a] = false;
      }
    }
  }
  vector<int> ban(m);
  for (int i=0;i<m;i++){
    int mx = -1;
    for (int a : A[i]) {
      mx = max(mx, f[a]);
    }
    if (mx > i) ban[i] = true;
  }
  vector<int> B2(n);
  for (int i=0;i<n;i++){
    bool ok = true;
    for (int j : inv[i]) {
      if (ban[j]) ok = false;
    }
    if (B[i] && f[i] == -1 && ok) {
      B2[i] = true;
    }
  }
  auto ans = B2;
  for (int i=0;i<m;i++){
    bool tt = false;
    for (int j : A[i]) {
      if (B2[j]) tt = true;
    }
    if (tt) {
      for (int j : A[i]) {
        B2[j] = true;
      }
    }
  }
  if (B == B2) {
    cout << "YES" << "\n";
    for (int a : ans) cout << a << " ";
  } else {
    cout << "NO" << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
