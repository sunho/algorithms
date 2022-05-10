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
  string s;
  cin >> s;
  map<pair<string,string>, ll> left;
  ll ans = 0;
  for(int mask = 0; mask <(1<<n); mask++){
    string a,b;
    for(int i=0;i<n;i++){
      if (mask >> i & 1) {
        a.push_back(s[i]);
      } else {
        b.push_back(s[i]);
      }
    }
    reverse(all(a));
    reverse(all(b));
    left[{a,b}]++;
  }
  for(int mask = 0; mask <(1<<n); mask++){
    string a,b;
    for(int i=0;i<n;i++){
      if (mask >> i & 1) {
        a.push_back(s[i+n]);
      } else {
        b.push_back(s[i+n]);
      }
    }
    ans += left[{a,b}];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
