#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int x;
  cin >> x;
  vector<int> A;
  for (int i=0;i<30;i++){
    if (x == 1 << i) break;
    if (x & (1 << i)) {
      A.push_back(x);
      x -= 1 << i;
    }
  }
  while (x != 1) {
    A.push_back(x);
    x -= x/2;
  }
  A.push_back(1);
  cout << A.size() << "\n";
  for (int x : A) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
