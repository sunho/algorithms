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
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++)
    cin >> A[i];
  {
    auto f = [&](ll K) {
      vector<ll> B(n);
      for(int i=0;i<n;i++)
        B[i] = (ll)A[i]*10000 - K;
      vector<ll> dp(n, -1e18);
      for (int i=0;i<n;i++){
        if (i - 1 >= 0) {
          ckmax(dp[i], dp[i-1] + B[i]);
        } else {
          ckmax(dp[i], B[i]);
        }
        if (i - 2 >= 0) {
          ckmax(dp[i], dp[i-2] + B[i]);
        } else {
          ckmax(dp[i], B[i]);
        }
      }
      if (n >= 2 && dp[n-2] >= 0)
        return true;
      return dp[n-1] >= 0;
    };
    ll ok = 0*10000, ng = (2e9+1)*10000;
    while (ng-ok>1) {
      ll mid = (ok+ng) / 2;
      if (f(mid)) ok = mid;
      else ng = mid;
    }
    cout << fixed<<setprecision(4) << ((long double)ok / 10000.0)<< "\n";
  }
  {
    auto f = [&](int K) {
      vector<int> B(n);
      for(int i=0;i<n;i++)
        B[i] = A[i] >= K ? 1 : -1;
      vector<int> dp(n, -1e9-1);
      for (int i=0;i<n;i++){
        if (i - 1 >= 0) {
          ckmax(dp[i], dp[i-1] + B[i]);
        } else {
          ckmax(dp[i], B[i]);
        }
        if (i - 2 >= 0) {
          ckmax(dp[i], dp[i-2] + B[i]);
        } else {
          ckmax(dp[i], B[i]);
        }
      }
      if (n >= 2 && dp[n-2] > 0)
        return true;
      return dp[n-1] > 0;
    };
    int ok = -1, ng = 1e9+1;
    while (ng - ok > 1) {
      int mid = (ok+ng) / 2;
      if (f(mid)) ok = mid;
      else ng = mid;
    }
    cout << ok << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
