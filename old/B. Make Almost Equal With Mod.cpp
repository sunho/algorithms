#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  bool done = false;
  ll ans = 2;
  while (true) {
    set<ll> S;
    for (int i=0;i<n;i++) {
      S.insert(A[i] % ans);
    }
    if (S.size() == 2) {
      break;
    }
    ans *= 2;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)
    solve();
}
