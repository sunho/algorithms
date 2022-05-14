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
  vector<pair<int,int>> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  ll maxi = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      auto [x,y] = A[i];
      auto [x2,y2] = A[j];
      ckmax(maxi, (ll)(x-x2)*(x-x2) + (ll)(y-y2)*(y-y2));
    }
  }
  cout << fixed << setprecision(10) << sqrtl(maxi) << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
