#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll B, K;
  cin >> B >> K;
  ll x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  auto block_points = [&](ll x, ll y) {
    vector<pair<ll,ll>> cands;
    ll bi = x/B, bj = y/B;
    cands.push_back({x, bj*B});
    cands.push_back({x, (bj+1)*B});
    cands.push_back({bi*B, y});
    cands.push_back({(bi+1)*B, y});
    return cands;
  };
  auto b1 = block_points(x1, y1);
  auto b2 = block_points(x2, y2);
  pair<ll,ll> s = {x1,y1};
  pair<ll,ll> t = {x2,y2};
  auto dist = [&](pair<ll,ll> a, pair<ll,ll> b) {
    return abs(1LL * a.first - b.first) + abs(1LL * a.second - b.second);
  };
  auto dist2 = [&](pair<ll,ll> a, pair<ll,ll> b) {
    ll X1 = a.first / B, Y1 = a.second / B, X2 = b.first / B, Y2 = b.second / B;
    if (Y1 == Y2 && X1 != X2) {
      return min(a.second % B + b.second % B, 2*B - a.second % B - b.second % B) + abs(a.first - b.first);
    }
    if (X1 == X2 && Y1 != Y2) {
      return min(a.first % B + b.first % B, 2*B - a.first % B - b.first % B) + abs(a.second - b.second);
    }
    return dist(a,b);
  };
  ll ans = K * dist(s,t); 
  for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
      ll cand2 = dist(s,b1[i])*K + dist2(b1[i], b2[j]) + dist(b2[j], t)*K;
      ans = min(cand2, ans);
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
