#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    int a;
    cin >> a;
    bool start = false;
    vector<int> ans;
    if (a % 2 == 0) {
      cout << -1 << "\n";
      continue;
    }
    for (int i=30;i>=1;i--) {
      if (a & (1<<i)) {
        if (!start) {
          start = true;
        }
        ans.push_back(2);
      } else {
        if (start) {
          ans.push_back(1);
        }
      }
    }
    cout << ans.size() << "\n";
    for (int v : ans) {
      cout << v << " ";
    }
    cout << "\n";
  }
}
