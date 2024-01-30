#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int a,b;
  cin >> a >> b;
  if ((a+b)%2 == 0) {
    cout << "Bob" << "\n";
  } else {
    cout << "Alice" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
