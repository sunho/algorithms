#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,x;
  cin >> n >> x;
  vector<int> A(n), B(n);
  for (int i=0;i<n;i++){
    cin >> A[i] >> B[i];
  }
  const ll inf = (ll)2e18 + 100;
  ll ans = inf;
  ll cur = 0;
  for (int i=0;i<n;i++){
    cur += A[i] + B[i];
    ll cand = cur;
    int rem = (x-i-1);
    if (rem > 0) {
      cand += 1LL * rem * B[i];
    }
    ans = min(ans, cand);
  }
  cout << ans << "\n";
}
