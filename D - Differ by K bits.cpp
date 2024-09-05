#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int g (int n) {
  return n ^ (n >> 1);
}

void solve() {
  int n,k;
  cin >> n >> k;
  if (n == k && k == 1) {
    cout << "Yes" << "\n";
    cout << 0 << " " << 1 << "\n";
    return;
  }
  if (k%2 == 0 || n == k) {
    cout << "No" << "\n";
    return;
  }
  cout << "Yes" << "\n";
  vector<int> B(n);
  for (int i=0;i<k-1;i++){
    B[i] = ((1 << (k+1)) - 1) ^ (1 << i);
  }
  for (int i=k-1;i<n;i++){
    B[i] = ((1 << (k-1)) - 1) ^ (1 << i);
  }
  for (int i=0;i<(1<<n);i++){
    int m = g(i);
    int a = 0;
    for (int j=0;j<n;j++){
      if (m >> j & 1) {
        a ^= B[j];
      }
    }
    cout << a << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
