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
  vector<pair<int,bool>> H(n);
  int ans = 0;
  for (int i=0;i<n;i++){
    char c;
    cin >> c;
    H[i].second = !(c-'0');
    ans += !H[i].second;
  }
  for (int i=0;i<n;i++){
    cin >> H[i].first;
  }
  sort(all(H));
  int cur = ans;
  for (int i=0;i<n;i++){
    if (!H[i].second) {
      cur--;
    } else {
      cur++;
    }
    ans = max(cur, ans);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
