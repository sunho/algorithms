#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
  
ll normalize(ll x, ll mod) { x %= mod; if (x < 0) x += mod; return x; }
tuple<ll,ll,ll> exgcd(ll a, ll b) {
  ll x = 1, y = 0;
  ll x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    ll q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return {a1,x,y};
}
  
template<typename T>
ll do_crt(vector<T>& a, vector<T>& m) {
  ll ans = a[0];
  ll l = m[0];
  for(int i = 1; i < (int)a.size(); i++) {
    auto [d, x1, y1] = exgcd(l, m[i]);
    if((a[i] - ans) % d != 0) {
      return -1;
    }
    ans = normalize(ans + x1 * (a[i] - ans) / d % (m[i] / d) * l, l * m[i] / d);
    l = lcm(l, m[i]);
  }
  return ans;
}
  
vector<ll> factorize(ll n) {
  vector<ll> facts;
  for (ll d = 2; d * d <= n; d++) {
    ll dd=1;
    while (n % d == 0) {
      n /= d;
      dd *= d;
    }
    if (dd != 1) {
      facts.push_back(dd);
    }
  }
  if (n > 1)
    facts.push_back(n);
  return facts;
}
  
void solve() {
  ll n;
  cin >> n;
  ll ans = n-1;
  if (n==1) {
    cout << 1 << "\n";
    return;
  }
  auto factors = factorize(n);
  if (factors.size() == 1) {
    cout << ans << "\n";
    return;
  }
  factors = factorize(2*n);
  for(int mask = 0; mask < (1 << factors.size()); mask++) {
    vector<ll> a;
    vector<ll> m;
    for(int i=0;i<(int)factors.size();i++) {
      if (mask & (1 << i)) {
        a.push_back(-1);
      } else {
        a.push_back(0);
      }
      m.push_back(factors[i]);
    }
    ll cand = do_crt(a,m);
    if (cand <= 1) continue;
    ans = min(ans, cand);
  }
  cout << ans << "\n";
}
  
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  
  solve();
  
  return 0;
}