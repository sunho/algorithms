#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n, h, x;
  cin >> n >> h >> x;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (h + a >= x) {
      cout << i + 2 << "\n";
      return 0;
    }
  }
}
