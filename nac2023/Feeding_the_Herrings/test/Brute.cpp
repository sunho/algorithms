#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n,l;
    cin >> n >> l;
    int ans = 0;
    for (int i=l;i<=n;i++){
      for (int j=l;j<=n;j++){
        for (int k=l;k<=n;k++){
          if (i+j+k != n) continue;
          if (to_string(i).find('3') != string::npos || to_string(j).find('3') != string::npos || to_string(k).find('3') != string::npos) continue;
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
}
