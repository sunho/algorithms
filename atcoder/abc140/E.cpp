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
  vector<int> A(n);
  vector<int> inv(n+1);
  for(int i=0;i<n;i++) {
    cin >> A[i];
    inv[A[i]] = i;
  }
  set<int> high;
  high.insert(-1), high.insert(n);
  ll ans = 0;
  for(int p=n;p>=1;p--){
    int i = inv[p];
    int l = *(--high.lower_bound(i));
    int r = *high.upper_bound(i);
    int pl = l, pr = r;
    if (pl != -1) pl = *(--high.lower_bound(pl));
    if (pr != n) pr = *high.upper_bound(pr);
    ans += (ll)p * (l-pl) * (r-i);
    ans += (ll)p * (pr-r) * (i-l);
    high.insert(inv[p]);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
