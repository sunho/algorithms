#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T, auto combine,auto default_value=0> struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n+1)*2) {}

  void update(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = bits[k*2] + bits[k*2+1];
  }
  T query(int l, int r) {
    T resl = {}, resr = {};
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) resl = resl + bits[l++];
      if (!(r & 1)) resr = bits[r--] + resr;
    }
    return resl + resr;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> F(n);
  for(int i=0;i<n;i++) cin >> F[i];
  vector<ll> D(n);
  for(int i=0;i<n;i++) cin >> D[i];
  int ans = n;
  for (int j=0;j<n;j++){
    ll x = F[j]*D[j];
    ll mx = x+k;
    vector<ll> imos(mx-x+2);
    ll len = mx-x+1;
    for (int l=0;l<n;l++){
      ll m = x/F[l];
      if (F[l] > k) {
        ll L = m*F[l]+k+1, R = (m+1)*F[l];
        imos[clamp(L-x, 0ll, len)] += n;
        imos[clamp(R-x, 0ll, len)] -= n;
        L += F[l], R += F[l];
        imos[clamp(L-x, 0ll, len)] += n;
        imos[clamp(R-x, 0ll, len)] -= n;
      }
      if (m == 0) {
        imos[0] += n;
        imos[clamp(1ll*k+1-x, 0ll, len)] -= n;
      }
      ll p = F[l]*D[l];
      imos[0]++;
      imos[len]--;
      imos[clamp(p-x, 0ll, len)]--;
      imos[clamp(p-x+k+1, 0ll, len)]++;
    }
    for (int i=1;i<=len;i++){
      imos[i] += imos[i-1];
    }
    for (int i=0;i<len;i++){
      ans = min((ll)ans, imos[i]);
    }
  }
  cout << ans << "\n";
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
