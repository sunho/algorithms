#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n,k;
    cin >> n >> k;
    int chunks = (n+k-1)/k;
    if (chunks > k) {
      cout << "IMPOSSIBLE" << "\n";
      continue;
    }
    int cur = 0;
    for (int i=0;i<chunks;i++){
      for (int j=0;j<k;j++){
        if (cur + (k-j-1) < n)
          cout << cur + (k-j-1) + 1 << " ";
      }
      cur += k;
    }
    
    cout << "\n";
  }
}
