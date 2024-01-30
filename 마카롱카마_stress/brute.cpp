#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = s;
  int ans = 0;
  sort(begin(t),end(t));
  do {
    string a(n, '0');
    for (int i=0;i<n;i++){
      a[i] = max(s[i],t[i]);
    }
    auto a2 = a;
    reverse(begin(a2),end(a2));
    if (a == a2) {
      ans = max(ans, stoi(a));
    }
  } while(next_permutation(begin(t), end(t)));
  cout << ans;
}

int main() { solve(); }
