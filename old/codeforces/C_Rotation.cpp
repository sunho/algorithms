#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  int cur = 0;
  while(q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      cur -= x;
      cur = (cur%n + n) % n;
    } else {
      int x;
      cin >> x;
      --x;
      cout << s[(cur+x)%n] << "\n";
    }
  }
}
