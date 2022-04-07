#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


struct trie_vertex {
  array<int, 26> next;
  bool leaf = false;
  trie_vertex () {
    fill(begin(next), end(next), -1);
  }
};

void solve() {
  string S;
  cin >> S;
  string B;
  cin >> B;
  int k;
  cin >> k;
  vector<trie_vertex> trie(1);
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
      if (trie[v].next[c] == -1) {
        trie[v].next[c] = trie.size();
        trie.push_back({});
        ans++;
      }
      v = trie[v].next[c];
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
