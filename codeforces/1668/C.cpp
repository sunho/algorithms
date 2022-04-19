#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<ll> B(n);
  auto go = [&](int z) {
    ll ans = 0;
    for(int i=0;i<n;i++) B[i] = 0;
    for(int i=z-1;i>=0;i--) {
      ll k = (-B[i+1])/A[i] + 1;
      B[i] = -k*A[i];
      ans += k;
    }
    for(int i=z+1;i<n;i++) {
      ll k = (B[i-1])/A[i] + 1;
      B[i] = k*A[i];
      ans += k;
    }
    return ans;
  };
  ll ans = 1e18;
  for(int i=0;i<n;i++) {
    ans = min(ans, go(i));
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
