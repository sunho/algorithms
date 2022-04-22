#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  const ll inf = 1e9+10;
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(all(A));
  vector<ll> pf(n+1);
  for(int i=0;i<n;i++){
    pf[i+1]=pf[i]+A[i];
  }

  auto f = [&](int i, ll d) {
    return pf[i+1] + d*(i+1);
  };

  ll ans = 0;
  ll d = 0;
  int p = 0;
  int k = 5;
  while(true) {
    { 
      int l = -1, r = n;
      while(r-l>1){
        int mid = (l+r)/2;
        if (f(mid, d) <= x) l = mid;
        else r = mid;
      }
      if(l == -1) {
        break;
      }
      p = l;
    }
    { 
      ll l = d, r = inf+1;
      while(r-l>1){
        ll mid = (l+r)/2;
        if (f(p, mid) <= x) l = mid;
        else r = mid;
      }
      ans += (r-d)*(p+1);
      d = r;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
