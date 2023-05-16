#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];

  int sum = 0;
  for (int i=0;i<n;i++) sum ^= A[i];
  if (sum == 0) {
    cout << "second" << "\n";
  } else {
    cout << "first" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
}
