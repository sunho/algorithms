#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--){
    string s;
    cin >> s;
    int n = s.size();
    if (s == "()") {
      cout << "NO" << "\n";
      continue;
    }
    string cand1,cand2; 
    for (int i=0;i<n;i++) {
      cand1.push_back('(');
    }
    for (int i=0;i<n;i++) {
      cand1.push_back(')');
    }
    for (int i=0;i<n;i++){
      cand2.push_back('(');
      cand2.push_back(')');
    }
    cout << "YES" << "\n";
    bool ok = true;
    for (int i=0;i<=n;i++) {
      if (cand1.substr(i,n) == s) {
        ok = false;
      }
    }
    if (ok) {
      cout << cand1 << "\n";
    } else {
      cout << cand2 << "\n";
    }
  }

}
