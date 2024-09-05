#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128_t;

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  auto S = A;
  sort(begin(S),end(S));
  const lll inf = 1e18;
  auto check = [&](lll x)  {
    lll ok = 0, ng = inf+1;
    while(ng-ok>1) {
      lll mid = (ok+ng)/2;
      if (x >= mid*mid) ok = mid;
      else ng = mid;
    }
    return ok*ok == x;
  };
  for (int i=0;i<n;i++){
    if (S[i] != A[i]) {
      if (!check((lll)S[i]*A[i])) {
        cout << "NO" << "\n";
        return;
      }
    }
  }
  cout << "YES";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
