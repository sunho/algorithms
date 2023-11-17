#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    auto f = [&](int x) -> int {
      auto s = to_string(x);
      return *max_element(begin(s),end(s))-*min_element(begin(s),end(s));
    };
    int ans = 0;
    int y = 0;
    for (int i=l;i<=r;i++){
      if (ans <= f(i)) {
        ans = f(i);
        y = i;
      }
      if (ans == 9) break;
    }
    cout << y << "\n";
  }
}
