#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  if (n%2 == 1) {
    for (int i=0;i<q;i++){
      int a;
      cin >> a;
      cout << "NO" << "\n";
    }
    return 0;
  }
  set<int> open, close;
  for (int i=0;i<n-1;i++){
    if (s[i] == '(' && s[i+1] == '(') {
      open.insert(i);
    }
    if (s[i] == ')' && s[i+1] == ')') {
      close.insert(i);
    }
  }
  while (q--){
    int x;
    cin >> x;
    --x;
    if (s[x] == '(') {
      s[x] = ')';
    } else {
      s[x] = '(';
    }
    if (x-1>=0) {
      open.erase(x-1), close.erase(x-1);
      if (s[x-1] == '(' && s[x] == '(') {
        open.insert(x-1);
      }
      if (s[x-1] == ')' && s[x] == ')') {
        close.insert(x-1);
      }
    }
    if (x+1<n) {
      open.erase(x), close.erase(x);
      if (s[x] == '(' && s[x+1] == '(') {
        open.insert(x);
      }
      if (s[x] == ')' && s[x+1] == ')') {
        close.insert(x);
      }
    }
    if (s[0] == ')' || s.back() == '(') {
      cout << "NO" << "\n";
      continue;
    }
    if (open.empty() && close.empty()) {
      cout << "YES" << "\n";
    } else if (open.empty() && !close.empty()) {
      cout << "NO" << "\n";
    } else if (!open.empty() && close.empty()) {
      cout << "NO" << "\n";
    } else {
      if (*open.begin() < *close.begin() && *--open.end() < *--close.end()) {
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}

//()))()))())
