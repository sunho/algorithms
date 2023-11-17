#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x,y,k;
    cin >> x >> y >> k;
    if (x >= y) {
      cout << x << "\n";
    } else {
      cout << y + max(y-x-k, 0) << "\n";
    }
  }
}
