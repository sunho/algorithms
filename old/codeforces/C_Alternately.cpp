#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i=0;i<n-1;i++){
    if (s[i] == s[i+1]) {
      cout << "No" << "\n";
      return 0;
    } 
  }
  cout << "Yes" << "\n";
}
