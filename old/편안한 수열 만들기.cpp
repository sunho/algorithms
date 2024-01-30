#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  k = n-k;
  auto rev = [](int l, int r) {
    cout << "reverse " << l + 1 << " " << r+1 << "\n";
  };
  if (n == 3) {
    cout << "NO" << "\n";
    return;
  }
  if (n == 2) {
    cout << "YES" << "\n";
    for (int i=0;i<5;i++){
      cout << "swap 1 2" << "\n";
    }
    return;
  }
  if (k > 1 && n-k > 1) {
    cout << "YES" << "\n";
    rev(0,n-1);
    rev(0,n-1);
    rev(0,n-1);
    rev(0,k-1);
    rev(k,n-1);
  } else {
    cout << "YES" << "\n";
    if (k == 1) {
      rev(1,n-1);
      rev(0,1);
      rev(2,n-1);
      rev(0,n-1);
      rev(0,n-1);
    } else {
      rev(0,n-2);
      rev(0,n-3);
      rev(n-2,n-1);
      rev(0,n-1);
      rev(0,n-1);
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
