#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)

void solve() {
  int n,k,x;
  cin >> n >> k >> x;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  sort(all(A), greater<>());
  for(int i=0;i<n;i++) {
    int r = min(A[i]/x,k);
    k -= r;
    A[i] -= r*x;
  }
  sort(all(A), greater<>());
  for(int i=0;i<n;i++){
    if (k > 0) {
      k--;
      A[i] = 0;
    }
  }
  ll sum = 0;
  for(int i=0;i<n;i++) sum += A[i];
  cout << sum << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
