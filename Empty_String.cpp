#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  string s;
  cin >> s;
  int n = s.size();

  if (n & 1) {
    cout << 0 << "\n";
    return 0;
  }


  const int inf = 1e9;
  vector dp(n, vector<int>(n, 0));
  for (int k=0;k<n/2;k++){
    vector next(n, vector<int>(n, 0));
    for (int l=0;l<n;l++){
      for (int r=l+1;r<n;r++){
        if (s[l] == s[r]) {
          if (l + 1 == r) {
            next[l][r] = 1;
          } else {
            next[l][r] += 
          }
        }
      }
    }
  }
}
