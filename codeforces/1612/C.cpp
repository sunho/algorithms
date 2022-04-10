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
  ll k,x;
  cin >> k >> x;
  auto calc = [&](ll i) {
    ll sum = 0;
    if (i >= k) {
      sum += k*(k+1)/2;
      sum += k*(k-1)/2;
      sum -= (2*k-1-i)*(2*k-i)/2;
    } else {
      sum += (i*(i+1))/2;
    }
    return sum;
  };
  ll l = -1, r = 2*k;
  while (r-l > 1) {
    ll m = (l+r)/2;
    if (calc(m) >= x) {
      r = m;
    } else {
      l = m;
    }
  }
  if (r == 2*k) {
    cout << 2*k-1 << "\n";
  } else {
    cout << r << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
