#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(6);
  for (int i = 0; i < 6; i++) {
    cin >> A[i];
  }
  int t, p;
  cin >> t >> p;
  int ans1 = 0;
  for (int i = 0; i < 6; i++) {
    ans1 += (A[i] + t - 1) / t;
  }
  cout << ans1 << "\n";
  cout << n / p << " " << n % p << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
