#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int a,b;
  cin >> a >> b;
  // a = 2x + y
  // b = x + 2y
  // 2*a-b = 3x 
  // 2*b-a = 3y
  // a+b = 3(x+y)
  // 2*a-b >= 0 && 2*b-a >= 0
  if ((2*a - b) % 3 == 0 && (2*b - a) % 3 == 0 && 2*a >= b && 2*b >= a)
  cout << "YES" << "\n";
  else
  cout << "NO" << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
