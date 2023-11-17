#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, ll> A;
    for (int i=0;i<n;i++) {
      int a; cin >> a;
      A[a]++;
    }
    int q;
    cin >> q;
    while (q--) {
      ll x,y;
      cin >> x >> y;
      ll quad = x*x - 4*y;
      ll sq = sqrtl(quad);
      if (quad < 0 || sq * sq != quad) {
        cout << 0 << " ";
        continue;
      }
      ll ans = 0;
      set<ll> cands({x + sq});
      for (ll cand : cands) {
        if (cand % 2 != 0) continue;
        cand /= 2;
        ll other = x - cand;
        if (cand == other) {
          ans += A[cand]*(A[cand]-1)/2;
        } else {
          ans += A[cand]*A[other];
        }
      }
      cout << ans << " ";
    }
    cout << "\n";
  }
}
