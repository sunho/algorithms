#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;

  set<char> remain = set<char>({'A','C','G','T'});
  for(int i=0;i<s.size();i++){
    remain.erase(s[i]);
    if (remain.empty()) {
      cout << s[i];
      remain = set<char>({'A','C','G','T'});
    }
  }
  cout << *remain.begin();
}
