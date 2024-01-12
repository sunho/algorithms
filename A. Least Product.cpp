#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  int neg = 0;
  int zero = 0;
  for (int i=0;i<n;i++) {
    cin >> A[i];
    if (A[i] == 0) {
      zero++;
    } else if (A[i] < 0) {
      neg++;
    }
  }
  if ((zero == 0 && neg % 2 == 1) || zero != 0) {
    cout << 0 << "\n";
  } else {
    cout << 1 << "\n";
    cout << 1 << " " << 0 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
  solve();
}
