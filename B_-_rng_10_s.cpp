#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  if (b > d || b > a) {
    cout << "No" << "\n";
    return;
  }
  // c < b
  if (b <= c) {
    cout << "Yes" << "\n";
    return;
  }

  ll mini = c-b+1;
  ll mod = ((mini % gcd(d,b)) + gcd(d,b)) % gcd(d,b);
  ll aa = a % gcd(d,b);
  if (mod != aa) {
    if (mod < aa) {
      mini += aa-mod;
    } else {
      mini += gcd(d,b) - mod + aa;
    }
  }
  if (mini < 0) {
    cout << "No" << "\n";
  } else {
    cout << "Yes" << "\n";
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
