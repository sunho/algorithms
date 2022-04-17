#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,a,b;
  cin >> n >> a >> b;
  vector<ll> A(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
  }
  vector<ll> pf(n+1);
  for(int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  ll sum = 0;
  ll ans = pf[n]*b;
  for(int i=0;i<n;i++) {
    ll cand = pf[n]*b - (sum+A[i]*(n-i-1))*b + A[i]*a;
    ans = min(ans, cand);
    sum += A[i];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
