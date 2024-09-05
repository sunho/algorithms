#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  int g = A.back()-A[0];
  for (int i=0;i<n;i++){
    g = gcd(g, 2*(A[i]-A[0]));
  }
  cout << (A[0] % g) + A.back()-A[0];
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
