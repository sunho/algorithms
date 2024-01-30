#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i=0;i<n;i++){
    for (int c=0;c<k;c++){
      cout << (char)('a' + c);
    }
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
