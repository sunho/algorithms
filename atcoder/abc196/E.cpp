#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  const ll inf = 1e18;
  int n;
  cin >> n;
  ll y = 0, low = inf, high = -inf;
  for(int i=0;i<n;i++) {
    ll a,t;
    cin >> a >> t;
    if (t==1) {
      y+=a;
      low+=a;
      high+=a;
    } else if(t==2) {
      low = max(low, a);
      high = max(high, a);
    } else {
      low = min(low, a);
      high = min(high, a);
    }
  }
  int q;
  cin >> q;
  while(q--){
    ll x;
    cin >> x;
    x += y;
    x = min(x,low);
    x = max(x,high);
    cout << x << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
