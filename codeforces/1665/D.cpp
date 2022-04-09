#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
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

void solve() {
  vector<int> coprimes = {4,9,5,7,11,13,17,19,23};
  set<int> added;
  vector<int> a;
  vector<int> m;
  ll L = 1;
  for(auto x : coprimes) L *= x;
  for(int i=1;i<=23;i++) {
    cout << "? " << L + i << " " << i << endl;
    ll p;
    cin >> p;
    for(auto x : coprimes) {
      if (p % x == 0 && !added.count(x)) {
        a.push_back(((-i % x) + x) % x);
        m.push_back(x);
        added.insert(x);
      }
    }
  }
  ll ans = a[0];
  ll l = m[0];
  for(int i = 1; i < a.size(); i++)
  {
    auto [d, x1, y1] = exgcd(l, m[i]);
    ans = normalize(ans + x1 * (a[i] - ans) / d % (m[i] / d) * l, l * m[i] / d);
    l *= m[i];
  }

  cout << "! " << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }

  return 0;
}
