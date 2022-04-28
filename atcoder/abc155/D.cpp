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
  vector<ll> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  sort(all(A));
  array<int,3> cnt{};
  for(int i=0;i<n;i++){
    if (A[i] > 0) cnt[2]++;
    else if (A[i] < 0) cnt[0]++;
    else cnt[1]++;
  }
  ll zero = (ll)cnt[1]*(cnt[1]-1)/2 + (ll)cnt[1]*cnt[0] + (ll)cnt[1]*cnt[2];
  ll neg = (ll)cnt[0]*cnt[2];
  ll pos = (ll)n*(n-1)/2 - zero - neg;
  int p_start = cnt[1]+cnt[0];
  k--;
  if (k >= neg && k < neg + zero) {
    cout << 0 << "\n";
    return;
  }
  auto go = [&](ll x) {
    ll res = 0;
    if (x < 0) {
      for(int i=0;i<cnt[0];i++){
        ll v = x / A[i];
        res += n - ub(A,v);
      }
      return res;
    } else {
      for(int i=0;i<cnt[0];i++){
        ll v = x / A[i];
        int p = lb(A,v);
        if(p <= i) p++;
        res += cnt[0] - p;
      }
      for(int i=p_start;i<n;i++){
        ll v = x / A[i];
        int p = ub(A,v);
        if(p > i) p--;
        res += p - p_start;
      } 
    }
    
    return res/2;
  };
  ll l,r;
  if (k < neg) {
    l = -1e18-1, r =0;
    while(r-l > 1){
      ll m = l + (r-l)/2;
      if (go(m) <= k) l = m;
      else r = m;
    }
    cout << l << "\n";
  } else {
    l = 0, r = 1e18+1;
    k -= zero;
    k -= neg;
    while(r-l > 1){
      ll m = l + (r-l)/2;
      if (go(m) <= k) l = m;
      else r = m;
    }
    cout << r << "\n";
  }
  
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
