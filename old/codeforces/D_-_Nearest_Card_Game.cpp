#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  vector<ll> pf(n+1);
  for(int i=0;i<n;i++) pf[i+1] = pf[i]+A[i];
  vector<ll> epf(n+1);
  for(int i=0;i<n;i++) if (i%2==0) epf[i+1] = epf[i]+A[i];
  vector<ll> opf(n+1);
  for(int i=0;i<n;i++) if (i%2==1) opf[i+1] = opf[i]+A[i];

  sort(all(A));
  while(q--){
    int x;
    cin >> x;
    int ok=0,ng=n;

    while(ng-ok>1){
      int mid = (ok+ng)>>1;
      int r = n-mid-1;
      int l = r-mid;
      if (l < 0) {
        ng = mid;
        continue;
      }
      if (abs(A[l]-x) > abs(A[r]-x)) {
        ng = mid;
        continue;
      }
      ok = mid;
    }
    ll ans = pf[n]-pf[n-ok-1];
    if (n%2 == 1) 
      ans += epf[n-2*(ok+1)];
    else
      ans += opf[n-2*(ok+1)];
    cout << ans << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
