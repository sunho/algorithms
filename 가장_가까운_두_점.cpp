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
  vector<pair<ll,ll>> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  sort(all(A));
  if ((int)(unique(all(A)) - A.begin()) != n) {
    cout << 0 << "\n";
    return;
  }
  set<pair<ll,ll>> mpY;
  set<pair<ll,ll>> mpX;
  const ll inf = 1e18;
  ll h = inf;
  for(int i=0;i<n;i++) {
    auto [x,y] = A[i];
    ll hh = h == 0 ? 0 : (ll)sqrtl(h)+1;
    {
      auto it = mpX.lower_bound({x-hh,-inf});
      for(auto jt = mpX.begin(); jt != it;) {
        auto [x2,y2] = *jt;
        mpY.erase(mpY.find({y2,x2}));
        jt = mpX.erase(jt);
      }
    }
    {
      for(auto it = mpY.lower_bound({y-hh,-inf}); it != mpY.upper_bound({y+hh, inf}); it++) {
        auto [y2,x2] = *it;
        ll a = x2-x;
        ll b = y2-y;
        ckmin(h,a*a+b*b);
      }
    }
    mpX.insert({x,y});
    mpY.insert({y,x});
  }
  cout << h << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
