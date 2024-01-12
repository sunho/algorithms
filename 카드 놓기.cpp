#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> C(n);
  for (int i=0;i<n;i++){
    cin >> C[i];
  }
  list<int> ans;
  for (int i=n-1;i>=0;i--) {
    int c = C[i];
    if (c == 1) {
      ans.push_front(n-i);
    } else if (c == 2) {
      ans.insert(next(ans.begin()),n-i);
    } else {
      ans.push_back(n-i);

    }
  }
  for (int i : ans) {
    cout << i << " ";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
