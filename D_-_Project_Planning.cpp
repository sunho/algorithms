#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,k;
  cin >> n >> k;
  vector<ll> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  auto f = [&](ll p) {
    ll sum = 0;
    for(int i=0;i<n;i++) {
      sum += min(A[i],p);
    }
    return sum/k >= p;
  };
  ll l = -1, r = 1e18+1;
  while (r-l > 1) {
    ll mid = (l+r)/2;
    if (f(mid)) l = mid;
    else r = mid;
  }
  cout << l << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
