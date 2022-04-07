#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<int K = 26>
struct Trie {
  struct Vertex {
    array<int, K> next;
    bool leaf = false;
    char pch;
    Vertex(char ch='$') : pch(ch) {
      fill(begin(next), end(next), -1);
    }
  };
  int cnt = 0;
  vector<Vertex> t;
  Trie() : t(1) { }
  void add_string(const string& s) {
    bool ok = true;
    int v = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (t[v].next[c] == -1) {
        t[v].next[c] = t.size();
        t.emplace_back(ch);
      }
      v = t[v].next[c];
    }
    if (ok && !t[v].leaf) {
      t[v].leaf = true;
      cnt++;
    }
  }
};

void solve() {
  string S;
  cin >> S;
  string B;
  cin >> B;
  int k;
  cin >> k;
  Trie trie;
  int ans = 0;
  for(int i=0;i<S.size();i++) {
    int nk = k+1;
    int v=0;
    for(int j=i;j<S.size();j++) {
      int c = S[j]-'a';
      if (B[c] == '0') {
        nk--;
        if (nk == 0) {
          break;
        }
      }
      if (trie.t[v].next[c] == -1) {
        trie.t[v].next[c] = trie.t.size();
        trie.t.emplace_back(S[j]);
        ans++;
      }
      v = trie.t[v].next[c];
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
