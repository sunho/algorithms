#include <bits/stdc++.h>

using namespace std;

// Union Find using disjoint subset union
struct union_find {
  int n;
  vector<int> p;
  vector<int> sz;
  union_find(int n) : n(n), p(n), sz(n, 1) {
    iota(begin(p),end(p), 0);
  }
  int leader(int x) {
    if (p[x] == x)
      return x;
    return p[x] = leader(p[x]);
  }
  void unite(int x, int y) {
    int l = leader(x), s = leader(y);
    if (l == s) return;
    if (sz[s] > sz[l]) swap(s,l);
    p[s] = l, sz[l] += sz[s];
  }
};

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> rem, rem2;
  for (char c = 'a'; c <= 'z'; c++) {
    rem.insert(c);
    rem2.insert(c);
  }
  union_find uf(256);
  map<char, char> M;
  char fi = '0';
  for (int i=0;i<n;i++) {
    if (M.count(s[i])) {
      cout << M[s[i]];
    } else {
      char dec = '0';
      for (char c : rem) {
        if (uf.leader(c) != uf.leader(s[i])) {
          dec = c;
          break;
        }
      }
      if (dec == '0') {
        M[*rem2.begin()] = *rem.begin();
      } else {
        M[s[i]] = dec;
        rem.erase(dec);
        rem2.erase(s[i]);
      }
      uf.unite(dec, s[i]);
      cout << M[s[i]];
    }
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
