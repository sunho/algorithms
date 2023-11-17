#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int mx = 0;
    int cnt0 = 0, cnt1 = 0;
    for (int i=0;i<n;i++) {
      int a;
      cin >> a;
      if (a == 0) cnt0++;
      else cnt1++;
      mx = max(a,mx);
    }
    if (cnt0 - 1 <= cnt1) {
      cout << 0 << "\n";
    } else if (mx != 1) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
}
