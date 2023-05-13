#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i=0;i<n;i++){
    int a; cin >> a; sum ^= a;
  }
  if (sum % 4 == 0) {
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
