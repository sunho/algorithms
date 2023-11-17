#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n,k;
    cin >> n >> k;
    int pos = 1 << min(k,30);
    if (pos <= n) {
      cout << pos << "\n";
    } else {
      cout << n + 1 << "\n";
    }
  }

}
