#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  for (int i=0;i<s.size()-1;i++){
    if (s[i] == s[i+1]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
