#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m,r;
  cin >> n >> m >> r;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(rbegin(A),rend(A));
  vector<array<int,2>> B(m);
  for (int i=0;i<m;i++){
    cin >> B[i][0] >> B[i][1];
  }
  vector<int> C(r);
  for (int i=0;i<r;i++){
    cin >> C[i];
  }
  ranges::sort(B, [&](auto a, auto b) {
    return a[1] > b[1];
  });
  sort(rbegin(C),rend(C));
  vector<ll> pf(r+1);
  for (int i=0;i<r;i++){
    pf[i+1] = pf[i] + C[i];
  }
  ll cur = 0;
  int ptr = 0;
  ll ans = 0;
  for (int i=0;i<n;i++) {
    ll cand = pf[min(n-i-1,r)];
    int rem = A[i];
    while (rem && ptr < m) {
      int k = min(B[ptr][0], rem);
      B[ptr][0] -= k;
      rem -= k;
      cur += (ll)B[ptr][1] * k;
      if (B[ptr][0] == 0) 
        ptr++;
    }
    ans = max(ans, cur + cand);
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
