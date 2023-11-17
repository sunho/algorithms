#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n;
    ll c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    auto check = [&](int w) {
      ll sum = 0;
      for (int i=0;i<n;i++){
        ll side = (a[i]+(ll)2*w);
        sum += side*side;
        if (sum > c) return false;
      }
      return sum <= c;
    };
    int ok = -1, ng = 1e9;
    while (ng-ok>1){
      int mid = (ok+ng)/2;
      if (check(mid)) ok = mid;
      else ng = mid;
    }
    cout << ok << "\n";
  }
}
