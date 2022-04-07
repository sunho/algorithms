#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  ll n,a,b;
  cin >> n >> a >> b;
  ll mini = 1e18;
  pair<ll, ll> mx;
  ll N = sqrtl(6 * n)+1;
  if (a * b >= 6*n) {
    cout << a * b << "\n";
    cout << a << " " << b << "\n";
    return;
  }
  bool swp = false;
  if (a > b) {
    swap(a,b);
    swp = true;
  }
  for(ll i=a;i<=N;i++){
    ll l = -1, r = 6e9+1;
    while (r-l > 1) {
      ll m = (l+r)/2;
      if (i*m >= 6*n && m >= b) {
        r = m;
      } else {
        l = m;
      }
    }
    if (i*r >= 6*n) {
      if (ckmin(mini, i*r)) {
        mx = {i,r};
      }
    }
  }
  if (swp) {
    swap(mx.x, mx.y);
  }
  cout << mini << "\n";
  cout << mx.x << " " << mx.y << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
