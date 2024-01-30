#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int q;
  cin >> q;
  vector<int> able(31);
  while (q--) {
    int t,a;
    cin >> t >> a;
    if (t == 1) {
      able[a]++;
    } else {
      bool yes = true;
      for (int i=30;i>=0;i--) {
        int x = 1 << i;
        int c = able[i];
        while (c && a >= x) {
          a -= x;
          c--;
        }
      }
      if (a == 0) {
        cout << "YES" << "\n";
      } else {
        cout << "No" << "\n";
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
