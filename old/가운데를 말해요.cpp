#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  multiset<int> S;
  auto it = S.begin();
  int ptr = 0;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    S.insert(a);
    if (i == 0) {
      it = S.begin();
    } else {
      if (a >= *it && S.size() % 2 == 1) {
        it++;
      }
      if (a < *it && S.size() % 2 == 0) {
        it--;
      }
    }
    cout << *it << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
