#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    ll sum = 0;
    for (int i=0;i<n;i++) {
      int a;
      cin >> a;
      sum += a;
    }
    if (sum % 2 == 0) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}
