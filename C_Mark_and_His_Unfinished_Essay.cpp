#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,c,q;
  cin >> n >> c >> q;
  string s;
  cin >> s;
  map<ll,pair<ll,ll>> S;
  ll len = n;
  S.insert({0, {0,n}});
  for (int i=0;i<c;i++){
    ll l,r;
    cin >> l >> r;
    --l;
    S.insert({len, {l,r}});
    len += r-l;
  }
  while(q--) {
    ll k;
    cin >> k;
    --k;
    while (true) {
      auto it = --S.upper_bound(k);
      ll offset = k - it->first;
      k = it->second.first + offset;
      if (k < n) {
        cout << s[k] << "\n";
        break;
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
