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
  vector<int> pf(n);
  for (int i=0;i<n-1;i++){
    pf[i+1] = A[i] > A[i+1];
  }
  for (int i=0;i<n-1;i++){
    pf[i+1] += pf[i];
  }
  int q;
  cin >> q;
  while(q--){
    int l,r;
    cin >> l >> r;
    --l,--r;
    if (pf[r]-pf[l]==1 && A[l] > A[r]) {
      cout << 2 << "\n";
    } else if (pf[r]-pf[l]){
      cout << 3 << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
