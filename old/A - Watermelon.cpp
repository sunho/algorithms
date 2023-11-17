#include <bits/stdc++.h>

using namespace std;

int main() {
  int w;
  cin >> w;
  for (int i=1;i<w;i++){
    int b = w-i;
    if (b <= 0) continue;
    if (b%2 == 0 && i%2 == 0) {
      cout << "YES" << "\n";
      return 0;
    }
  }
  cout << "NO" << "\n";
}
