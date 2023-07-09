#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> A(n);
    for (int i=0;i<n;i++) cin >> A[i];
    ll ans = 0;
    int cnt = 0;
    for (int i=0;i<n;i++){
      if (A[i] <= q) {
        cnt++;
      } else {
        if (cnt >= k) {
          ans += (ll)(cnt-k+2)*(cnt-k+1)/2;
        }
        cnt = 0;
      }
    }
    if (cnt >= k) {
      ans += (ll)(cnt-k+2)*(cnt-k+1)/2;
    }
    cout << ans << "\n";
  }
}
