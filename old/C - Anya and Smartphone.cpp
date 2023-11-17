#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
  }
  vector<int> inv(n);
  for (int i=0;i<n;i++){
    inv[A[i]] = i;
  }
  auto calc_page = [&](int a) {
    return inv[a]/k;
  };
  int cur = 0;
  long long ans = 0;
  while (m--) {
    int a;
    cin >> a;
    a--;
    ans += abs(cur - calc_page(a)) + 1;
    if (inv[a] != 0) {
      int b = A[inv[a]-1];
      swap(A[inv[a]], A[inv[a]-1]);
      swap(inv[a], inv[b]);
    }
  }
  cout << ans << "\n";
}
