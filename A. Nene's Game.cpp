#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int k,q;
  cin >> k >> q;
  vector<int> A(k);
  for (int i=0;i<k;i++){
    cin >> A[i];
  }
  while (q--) {
    int n;
    cin >> n;
    cout << min(n, A[0]-1) << " ";
  }
  cout << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
