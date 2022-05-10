#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  set<char> S;
  string s;
  cin >> s;
  bool low = false, high = false;
  for(int i=0;i<(int)s.size();i++){
    if (S.count(s[i])) {
      cout << "No" << "\n";
      return;
    }
    if ('a' <= s[i] && s[i] <= 'z') low = true;
    if ('A' <= s[i] && s[i] <= 'Z') high = true;
    S.insert(s[i]);
  }
  if(low&&high) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
