#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int x1,y1;
    cin >> x1 >> y1;
    if (y1 == 1) {
      cout << "1\n";
      cout << x1 << " " << y1 << "\n";
    } else {
      cout << "2\n";
      cout << 1 << " " << y1-1 << "\n";
      cout << x1 << " " << y1 << "\n";
    }
  }
}
