#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k % 2 == 0) {
      sort(begin(s),end(s));
      cout << s << "\n";
    } else {
      string a;
      string b;
      for (int i=0;i<n;i++){
        if (i%2 == 0) {
          a.push_back(s[i]);
        } else {
          b.push_back(s[i]);
        }
      }
      sort(begin(a),end(a));
      sort(begin(b),end(b));
      for (int i=0;i<n;i++){
        if (i%2==0) {
          cout << a[i/2];
        } else {
          cout << b[i/2];
        }
      }
      cout << "\n";
    }
  }
}
