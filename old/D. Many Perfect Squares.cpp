#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool perfect_squre(ll x) {
  ll cand = sqrtl(x);
  for (ll y : {cand-1, cand, cand+1}) {
    if (y*y == x) {
      return true;
    }
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  vector<ll> cands;
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      int d = A[j] - A[i];
      for (int k=1;(ll)k*k<=d;k++){
        if (d % k == 0) {
          int u = d/k, v = k;
          cands.push_back((ll)(u-v)*(u-v)/4 - A[i]);
          cands.push_back((ll)(u-v)*(u-v)/4 - A[j]);
          cands.push_back((ll)(v-u)*(v-u)/4 - A[i]);
          cands.push_back((ll)(v-u)*(v-u)/4 - A[j]);
          cands.push_back((ll)(u+v)*(u+v)/4 - A[i]);
          cands.push_back((ll)(u+v)*(u+v)/4 - A[j]);
        }
      }
    }
  }
  cands.push_back(0);
  int ans = 1;
  for (ll x : cands) {
    if (x < 0) continue;
    if (x > (ll)1e18) continue;
    int cand = 0;
    for (int i=0;i<n;i++){
      if (perfect_squre(A[i]+x)) {
        cand++;
      }
    }
    ans = max(ans, cand);
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
