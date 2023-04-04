#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<ll,ll>> A(n);
  vector<int> L(k);
  for(int i=0;i<k;i++){
    cin >> L[i];
    L[i]--;
  }
  for(int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  double ans = 0;
  for(int i=0;i<n;i++){
    auto [x1, y1] = A[i];
    double dist = 1e18;
    for(int j=0;j<k;j++){
      auto [x2, y2] = A[L[j]];
      dist = min(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)), dist);
    }
    ans = max(dist, ans);
  }
  cout << fixed << setprecision(15) << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
