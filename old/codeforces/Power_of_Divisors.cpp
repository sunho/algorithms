#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int tau(ll x) {
  int res = 0;
  for (ll i=1;i*i<=x;i++){
    if (x%i==0){
      res+=i*i==x?1:2;
    }
  }
  return res;
}

const ll inf = (ll)1e18 + 3;

// a*3 < 10
// a < 4

ll capmul(ll a, ll b) {
  if (a < (inf+b-1)/b) {
    return a*b;
  }
  return inf;
}

ll binexp(ll x, ll n) {
  ll res = 1;
  while(n) {
    if (n&1) res = capmul(res,x);
    x = capmul(x,x);
    n /= 2;
  }
  return res;
}

ll nthroot(ll x, ll n) {
  ll ng = 1, ok = x;
  while (ok - ng > 1) {
    ll mid = (ok+ng)/2;
    if (binexp(mid, n) >= x) ok = mid;
    else ng = mid;
  }
  if (ok != x && binexp(ok, n) == x) {
    return ok;
  }
  return -1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll x;
  cin >> x;

  if (x == 1) {
    cout << 1 << "\n";
    return 0;
  }

  for (int y=64;y>=2;y--) {
    ll root = nthroot(x, y);
    if (root == -1) continue;
    if (tau(root) == y) {
      cout << root << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
}

