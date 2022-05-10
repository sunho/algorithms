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
  ll k;
  cin >> n >> k;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  vector<ll> pf(n+1);
  for(int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  ll ans = 0;
  map<ll, int> cnt;
  // pf[r+1] - pf[l] = k
  // iff pf[l] = pf[r+1]-k
  for(int i=0;i<n;i++){
    cnt[pf[i]]++;
    ans += cnt[pf[i+1]-k];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
