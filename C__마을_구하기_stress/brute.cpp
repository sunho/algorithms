#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  char c;
  string s;
  cin >> n >> c >> s;
  pair<int,string> ans = {111111,""};
  sort(begin(s),end(s));
  do {
    vector<int> A(n);
    for (int i=0;i<n;i++){
      if (s[i] == c) {
        A[i] = 1;
        if (i + 1 < n && s[i+1] != tolower(s[i])) {
          A[i+1] = 1;
        }
        if (i - 1 >= 0 && s[i-1] != tolower(s[i])) {
          A[i-1] = 1;
        }
      }
    }
    int cnt = accumulate(begin(A),end(A),0);
    ans = min(ans, {cnt, s});
  } while (next_permutation(begin(s),end(s)));
  cout << ans.second;
}

int main() { solve(); }
