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
    if (n == 2 || n == 3 || n == 4) {
      cout << "Bob" << "\n";
    } else {
      cout << "Alice" << "\n";
    }
  }
}
