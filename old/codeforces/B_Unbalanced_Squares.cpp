#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      if (j == n && n % 2 == 1) 
        cout << n*(i-1) + j << " "; 
      else {
        if (j % 2 == 1)
          cout << n*(i-1) + j + 1 << " ";
        else
          cout << n*(i-1) + j - 1 << " ";
      }
    }
    cout << "\n";
  }
}
