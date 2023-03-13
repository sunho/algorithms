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
  ll x;
  cin >> x;
  vector<ll> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  auto calcX = [&](ll x) {
    ll ret = 0;
    for(int i=n-1;i>=0;i--){
      ret += x / A[i];
      x %= A[i];
    }
    return ret;
  };
  map<ll, ll> dp;
  dp[0] = 0;
  auto setX = [&](auto& dp, ll key, ll value) {
    if (!dp.count(key)) {
      dp[key] = value;
    } else {
      ckmin(dp[key], value);
    }
  };
  for (int i=n-1;i>=0;i--){
    map<ll, ll> next;
    for (auto [s, cnt] : dp) {
      if (s > x) {
        ll t = (s-x)/A[i];
        setX(next, s - A[i]*t, dp[s] + t);
        setX(next, s - A[i]*(t+1), dp[s] + t + 1);
      } else {
        ll t = (x-s)/A[i];
        setX(next, s + A[i]*t, dp[s] + t);
        setX(next, s + A[i]*(t+1), dp[s] + t + 1);
      }
      setX(next, s, dp[s]);
    }
    dp = next;
  }
  cout << dp[x] << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
