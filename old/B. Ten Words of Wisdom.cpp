#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int mx = 0;
    int mx_i = 0;
    for (int i=0;i<n;i++){
      int a,b;
      cin >> a >> b;
      if (a <= 10) {
        if (b >= mx) {
          mx = b;
          mx_i = i;
        }
      }
    }
    cout << mx_i + 1 << "\n";
  }
}
