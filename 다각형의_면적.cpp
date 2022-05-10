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
  ll ans = 0;
  vector<pair<ll,ll>> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  for(int i=1;i<n-1;i++){
    pair<ll,ll> a = {A[i].first - A[0].first, A[i].second - A[0].second};
    pair<ll,ll> b = {A[i+1].first - A[0].first, A[i+1].second - A[0].second};
    ans += (a.first * b.second - a.second * b.first);
  }
  long double ans2 = abs(ans);
  ans2 /= 2.0;
  cout << fixed << setprecision(1) << ans2 << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
