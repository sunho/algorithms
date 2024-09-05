#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n);
  vector<vector<ll>> S(61);
  for (int i=0;i<n;i++){
    cin >> A[i];
    for (int j=60;j>=0;j--){
      if (A[i] >> j & 1) {
        S[j].push_back(A[i]);
        break;
      }
    }
  }
  ll cur = 0;
  vector<ll> B;
  for (int i=0;i<n;i++){
    bool delta = false;
    for (int j=0;j<=60;j++){
      if (cur >> j & 1)  continue;
      if (S[j].empty()) continue;
      ll x = S[j].back();
      B.push_back(x);
      S[j].pop_back();
      cur ^= x;
      delta = true;
      break;
    }
    if (!delta) {
      cout << "No" << "\n";
      return;
    }
  }
  cout << "Yes" << "\n";
  for (int i=0;i<n;i++){
    cout << B[i] << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
