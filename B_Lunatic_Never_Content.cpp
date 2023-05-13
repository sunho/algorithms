#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];

  vector<int> D;
  for (int i=0;i<n/2;i++){
    int diff = (max(A[i], A[n-i-1]) - min(A[i],A[n-i-1]));
    D.push_back(diff);
  }
  int m = D.size();
  bool palin = true;
  for (int i=0;i<m;i++){
    if (D[i] != 0) {
      palin = false;
    }
  }
  if (palin) {
    cout << 0 << "\n";
    return;
  }
  int ans = 0;
  for (int v : D) ans = gcd(ans, v);
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
