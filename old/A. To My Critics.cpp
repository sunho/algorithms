#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    array<int,3> a{};
    for (int i=0;i<3;i++) cin >> a[i];
    if (a[0] + a[1] >= 10 || a[1] + a[2] >=10 || a[0] + a[2] >=10) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}
