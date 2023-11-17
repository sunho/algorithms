#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  map<int,int> cnt;
  for (int i=0;i<n;i++){
    string s;
    cin >> s;
    int cur = 0;
    char last = ' ';
    for (int j=0;j<s.size();j++) {
      if (s[j] == '1') {
        if (last != s[j]) {
          cur++;
        }
      }
      last = s[j];
    }
    cnt[cur] ++;
  }
  cout << (--cnt.end())->first << " " << (--cnt.end())->second << "\n";
}
