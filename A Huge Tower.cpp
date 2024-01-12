#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 9;

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  vector<int> B;
  ll ans = 1;
  for (int i=0;i<n;i++){
    int cnt = end(B)-lower_bound(begin(B),end(B),A[i]-d);
    ans *= (cnt+1);
    ans %= MOD;
    B.push_back(A[i]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
