#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<pair<ld,ld>> S(n);
  for(int i=0;i<n;i++){
    cin >> S[i].first >> S[i].second;
  }
  auto dist = [](pair<ld,ld> a, pair<ld,ld> b) {
    ld x = a.first - b.first;
    ld y = a.second - b.second;
    return sqrtl(x*x+y*y);
  };
  if (n == 1) {
    cout << "0.00" << "\n";
    return;
  }
  ld ans = 0;
  vector<bool> used(n);
  used[0] = true;
  for(int k=0;k<n-1;k++){
    ld mini = 9e18;
    int chosen;
    for(int i=0;i<n;i++){
      if (!used[i]) continue;
      for(int j=0;j<n;j++){
        if (i==j) continue;
        if (used[j]) continue;
        if (ckmin(mini, dist(S[i],S[j]))) {
          chosen = j;
        }
      }
    }
    ans += mini;
    used[chosen] = true;
  }
  cout << fixed << setprecision(2) << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
