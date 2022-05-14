#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  const int F = 1e4;
  auto input_i = [&]() {
    string s;
    cin >> s;
    int d = 0;
    if (s.rfind('.') != string::npos) {
      string t = s.substr(s.rfind('.') + 1);
      d = stoi(t);
      for(int i=0;i<4-(int)t.size();i++) d *= 10;
      s = s.substr(0, s.rfind('.'));
    }
    return (ll)stoi(s)*F + d;
  };
  ll x0 = input_i();
  ll y0 = input_i();
  ll r = input_i(); 
  ll yh = (r + y0)/F;
  auto iceil = [](ll x, ll d){
    return x < 0 ? x / d : (x+d-1) / d;
  };
  ll yl = iceil(-r + y0, F);
  ll cnt = 0;
  auto f = [&](ll x, ll y) {
    __int128 yy = F*y - y0;
    __int128 xx = F*x - x0;
    return xx*xx + yy*yy <= (__int128)r*r;
  };
  for (ll y = yl; y <= yh; y++) {
    ll xl, xh;
    {
      ll ng = -1e6, ok = x0/F+1;
      while (ok-ng > 1) {
        ll mid = (ok+ng)/2;
        if (f(mid, y)) ok = mid;
        else ng = mid; 
      }
      xl = ok;
    }
    {
      ll ok = x0/F, ng = 1e6;
      while (ng-ok > 1) {
        ll mid = (ok+ng)/2;
        if (f(mid, y)) ok = mid;
        else ng = mid; 
      }
      xh = ok;
    }
    cnt += xh-xl+1; 
  }
  cout << cnt << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
