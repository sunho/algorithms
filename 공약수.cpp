#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }

// factor one number count p^k
// O(sqrt(n))
vector<pair<ll,int>> factorize(ll n) {
  vector<pair<ll,int>> facts;
  for (ll d = 2; d * d <= n; d++) {
    int k=0;
    while (n % d == 0) {
      n /= d;
      k++;
    }
    if (k != 0) {
      facts.push_back({d,k});
    }
  }
  if (n > 1)
    facts.push_back({n,1});
  return facts;
}

void solve() {
  ll a,b;
  cin >> a >> b;
  // lcm = p^max
  // gcd = p^min
  auto a_facts_o = factorize(a);
  auto b_factors = factorize(b);
  int n = (int)b_factors.size();
  vector<pair<ll,int>> a_factors;
  for(int i=0;i<n;i++) {
    int p = 0;
    for(int j=0;j<(int)a_facts_o.size();j++) {
      if (a_facts_o[j].first == b_factors[i].first) {
        p = a_facts_o[j].second;
      }
    }
    a_factors.push_back({b_factors[i].first, p});
  }
  ll ab = a*b;
  tuple<ll,ll,ll> ans = {1e18,0,0};
  for(int mask = 0; mask < (1<<n); mask++){
    ll x = 1;
    for(int i=0;i<n;i++) {
      if (mask >> i & 1) {
        x *= power(b_factors[i].first, a_factors[i].second);
      } else {
        x *= power(b_factors[i].first, b_factors[i].second);
      }
    }
    ll y = ab / x;
    ckmin(ans, {x+y,x,y});
  }
  auto [_,x,y] = ans;
  cout << x << " " << y << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
