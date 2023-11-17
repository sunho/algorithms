#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    vector<ll> A(n);
    for (int i=0;i<n;i++) {
      cin >> A[i];
    }
    ll cur = A[0];
    vector<pair<ll,ll>> B(n-1);
    for (int i=1;i<n;i++){
      B[i-1] = {(ll)c*(i+1) - A[i], A[i]};
    }
    sort(begin(B),end(B));
    bool ok = true;
    for (int i=0;i<n-1;i++){
      if (cur >= B[i].first) {
        cur += B[i].second;
        assert(ok);
      } else {
        ok = false;
      }
    }
    if (ok) {
      cout << "Yes" << "\n";
    } else {
      cout << "No" << "\n";
    }
  }
}
