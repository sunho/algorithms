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
  for(int i=0;i<n;i++) cin >> A[i];
  vector<array<int,2>> cnt(30);
  for(int i=0;i<n;i++){
    for(int j=0;j<30;j++){
      if (A[i] >> j & 1) {
        cnt[j][1]++;
      } else {
        cnt[j][0]++;
      }
    }
  }
  ll ans = 0;
  for(int i=0;i<n;i++){
    ans += A[i];
  }
  for(int i=0;i<n;i++){
    ll cand = 0;
    for(int j=0;j<30;j++){
      if (A[i] >> j & 1) {
        cand += (ll)cnt[j][0]*(1ll<<j);
      } else {
        cand += (ll)cnt[j][1]*(1ll<<j);
      }
    }
    ckmax(ans, cand);
  }

  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
