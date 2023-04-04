#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  auto f = [&](ll x) {
    ll cnt = 0;
    for (int a=1;a<=n;a++){
      ll b = min(x,(ll)a*n);
      cnt += b/a;
    }
    return cnt >= ((ll)n*n+1)/2;
  };
  ll ng=0, ok = 1e18;
  while(ok-ng>1){
    ll mid = (ok+ng)>>1;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}
