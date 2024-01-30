#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> Q(n);
  for (int i=0;i<n;i++){
    cin >> Q[i];
  }
  vector<ll> A(n);
  vector<ll> B(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  ll ans = 0;
  const int N = 1e6;
  auto work = [&](int c) {
    auto Q2 = Q;
    for (int i=0;i<n;i++){
      if (Q2[i] < c*A[i]) {
        return;
      }
      Q2[i] -= c*A[i];
    }
    ll c2 = 1e9;
    for (int i=0;i<n;i++){
      if (B[i] != 0) {
        c2 = min(c2, (ll)Q2[i]/B[i]);
      }
    }
    ans = max(ans, c+c2);
  };
  for (int c=0;c<=N;c++){
    work(c);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
