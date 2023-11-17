#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> A(m);
  for (int i=0;i<m;i++){
    cin >> A[i].first >> A[i].second;
    A[i].first--,A[i].second--;
  }
  int q;
  cin >> q;
  vector<int> pos(q);
  for (int i=0;i<q;i++){
    cin >> pos[i];
    pos[i]--;
  }
  auto check = [&](int k) {
    vector<int> B(n);
    for (int i=0;i<k;i++){
      B[pos[i]] = 1;
    }
    vector<int> pf(n+1);
    for (int i=0;i<n;i++){
      pf[i+1] = pf[i] + B[i];
    }
    for (int i=0;i<m;i++) {
      auto [l,r] = A[i];
      int cnt = pf[r+1] - pf[l];
      if (cnt > r-l+1-cnt)
        return true;
    }
    return false;
  };
  int ng = 0, ok = q+1;
  while (ok-ng>1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  if (ng == q) {
    cout << -1 << "\n";
  } else{
    cout << ok << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();  
  }
}
