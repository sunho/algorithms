#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    ll sum = 0;
    int cnt = 0;
    for (int i=0;i<n;i++){
      int a;
      cin >> a;
      sum += a-1;
      if (a != 1) cnt ++;
    }
    if (n == 1 || sum + cnt < n) {
      cout << "NO" << "\n";
    } else {
      cout << "YES" << "\n";
    }
  }
}
