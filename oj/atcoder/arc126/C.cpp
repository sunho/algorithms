#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(all(A));
  vector<ll> pf(n+1);
  for(int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  const ll N = 3e5;
  ll ans=0;
  for(ll c=1;c<=N;c++) {
    ll rem = k;
    for(ll m=0;m*c<=N;m++) {
      int l = lb(A,c*m+1);
      int r = ub(A,(m+1)*c-1);
      int cnt = r-l;
      ll sum = pf[r] - pf[l];
      rem -= cnt*(m+1)*c - sum;
      if (r == n) {
        break;
      }
      if (rem < 0) {
        break;
      }
    }
    if (rem >= 0) {
      ckmax(ans, c);
    }
  }

  auto f = [&](ll p) {
    ll rem = k;
    for(int i=0;i<n;i++) {
      rem -= p - A[i];
      if (rem < 0) return false;
    }
    return rem >= 0;
  };

  ll l = N, r = 1e18 + 1;
  while(r-l > 1) {
    ll mid = (r+l)/2;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (l != N) {
    ans = l;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
