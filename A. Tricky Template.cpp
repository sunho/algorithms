#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string a,b,c;
  cin >> a >> b >> c;
  bool yes = false;
  for (int i=0;i<n;i++){
    if ((a[i] != b[i] && (a[i] == c[i] || b[i] == c[i])) || (a[i] == b[i] && b[i] == c[i])) {

    } else {
      yes = true;
    }
  }
  if (yes){
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
