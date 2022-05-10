#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m,s;
  cin >> n >> m >> s;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<ll> pf(n+1);
  for(int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  long double ans = 0.0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n+1;j++) {
      int x = n-j; // m
      int y = j-i; // (s - m*x)/y
      if (s-x*m > m*y) { continue; }
      if (x*m > s) { continue; }
      ll sum1 = pf[n] - pf[j];
      ll sum2 = pf[j] - pf[i];
      long double res = sum1*m;
      if (y!=0) {
        res += (long double)sum2*(long double)(s-x*m)/y;
      }
      ans = max(ans, res);
    }
  }
  cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
