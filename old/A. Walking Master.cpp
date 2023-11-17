#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 > y2) {
      cout << -1 << "\n";
      continue;
    }
    int nx = x1+y2-y1;
    if (nx - x2 < 0) {
      cout << -1 << "\n";
      continue;
    }
    cout << y2-y1 + nx-x2 << "\n";
  }
}
