#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> P(n);
  for(int i=0;i<n;i++){
    cin >> P[i].first >> P[i].second;
  }
  if (k==1) {
    cout << "Infinity" << "\n";
    return;
  }
  map<pair<pair<ll,ll>,pair<ll,ll>>,set<int>> cnt;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) {
      if (i == j) continue;
      ll dx = P[j].first - P[i].first;
      ll dy = P[j].second - P[i].second;
      ll x1 = P[i].first;
      ll y1 = P[i].second;
      if (dx == 0) {
        cnt[{{x1,0}, {0,0}}].insert(i);
      } else {
        ll b1 = y1 * dx - x1*dy;
        ll db1 = dx;
        ll g1 = gcd(b1,db1);
        b1/=g1;
        db1/=g1;
        if (db1 < 0) {
          b1*=-1;
          db1*=-1;
        }
        if (b1 == 0) {
          db1 = 1;
        }
        ll m1 = dy;
        ll dm1 = dx;
        ll g2 = gcd(m1,dm1);
        m1 /= g2;
        dm1 /= g2;
        if (m1 == 0) {
          dm1 = 1;
        }
        if (dm1 < 0) {
          m1*=-1;
          dm1*=-1;
        }
        cnt[{{m1,dm1},{b1,db1}}].insert(i);
      }
    }
  }
  ll ans = 0;
  for (auto& [x, c] : cnt) {
    if (c.size() >= k) {
      ans ++;
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
