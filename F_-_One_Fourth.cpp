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
  vector<ll> area(n+1);
  vector<pair<ll,ll>> pts(n);
  for(int i=0;i<n;i++){
    cin >> pts[i].first >> pts[i].second;
  }
  auto cross = [](pair<ll,ll> x, pair<ll,ll> y) {
    return x.first * y.second - x.second * y.first;
  };
  ll sum = 0;
  for(int i=0;i<n;i++){
    sum += cross(pts[i], pts[(i+1)%n]);
    area[i+1] = sum;
  }
  auto sarea = [&](int i, int j) -> ll {
    ll s = 0;
    if (i < j) {
      s = area[j] - area[i];
      s += cross(pts[j], pts[i]);
    } else {
      s = area[n] - (area[i] - area[j]);
      s += cross(pts[j], pts[i]);
    }
    return abs(s);
  };
  ll ans = numeric_limits<ll>::max();
  ll p = abs(area[n]);
  for (int i=0;i<n;i++) {
    int l = i+1;
    int r = i+n-1;
    while(r-l > 1) {
      int mid = (r+l) / 2;
      if (4*sarea(i,mid%n) >= p) {
        r = mid;
      } else {
        l = mid;
      }
    }
    if (r != i+n-1) {
      ans = min(ans, abs(4*sarea(i,r%n)-p));
    }
    if (l != i+1) {
      ans = min(ans, abs(4*sarea(i,(l)%n)-p));
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
