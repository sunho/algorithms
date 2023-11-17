#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){ 
    int a,b,c;
    cin >> a >> b >> c;
    if (c % 2 == 1) {
      if (a >= b) {
        cout << "First" << "\n";
      } else {
        cout << "Second" << "\n";
      }
    } else {
      if (a > b) {
        cout << "First" << "\n";
      } else {
        cout << "Second" << "\n";
      }
    }
  }
}
