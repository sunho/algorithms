#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  ll P, l, t;
  cin >> n >> P >> l >> t;
  int cnt2 = ((n-1)/7+1)/2;
  int cnt2_rem = ((n-1)/7+1)%2;
  auto ceildiv = [](ll x, ll y) {
    return (x+y-1)/y;
  };
  if (P<=(l+2*t)*cnt2) {
    cout << n- ceildiv(P, l+2*t) << "\n";
  } else if (P <= (l+2*t)*cnt2 + (l+t)*cnt2_rem) {
    cout << n - (cnt2 + cnt2_rem) << "\n";
  } else {
    ll ans = P - (l+2*t)*cnt2 - (l+t)*cnt2_rem;
    cout << n-(cnt2+cnt2_rem+ceildiv(ans, l)) << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
  solve();
}
