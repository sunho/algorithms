#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;
  for (int i=0;i<s.size();i++){
    cout << (char)toupper(s[i]);
  }
}
