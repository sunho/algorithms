#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  ll ans = 0;
  if (n%2 == 0) {
    for (int i=0;i<n/2;i++){
      ans -= A[i];
    }
    for (int i=n/2;i<n;i++){
      ans += A[i];
    }
    ans*=2;
    ans -= A[n/2] - A[n/2-1];
  } else {
    for (int i=0;i<n/2;i++){
      ans -= A[i];
    }
    for (int i=n/2+1;i<n;i++){
      ans += A[i];
    }
    ans*=2;
    ans -= A[n/2+1] - A[n/2-1];
    ans += max(A[n/2+1]-A[n/2],A[n/2]-A[n/2-1]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
