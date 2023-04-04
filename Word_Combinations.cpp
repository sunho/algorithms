#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct trie_node {
  trie_node() {
  }
  int cnt = 0;
  array<unique_ptr<trie_node>, 26> next;
};

const int N = (int)1e6+1;
unique_ptr<trie_node> root;

void trie_insert(const string& s) {
  int cur = 0;
  for (int i=0;i<s.size();i++){
    trie_node* cur = root.get();
    if (!cur->next[s[i]-'a']){
      cur->next[s[i]-'a'] = make_unique<trie_node>();
    }
    cur = cur->next[s[i]-'a'].get();
  }
  cur->cnt++;
}

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
struct mint {
  int v;
  mint() : v(0) {}
  mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  nodes.push_back({});
  string s;
  cin >> s;
  int n;
  cin >> n;
  for (int i=0;i<n;i++) {
    string t;
    cin >> t;
    trie_insert(t);
  }
  int m = s.size();
  vector<mint> dp(m+1);
  dp[0] = 1;
  for (int i=0;i<s.size();i++){
    int cur = 0;
    for (int j=i;j<s.size();j++) {
      if (nodes[cur].next[s[j]-'a'] == -1)
        break;
      cur = nodes[cur].next[s[j]-'a'];
      if (j+1<=m) {
        dp[j+1] += dp[i] * nodes[cur].cnt;
      }
    }
  }
  cout << dp[m].v << "\n";
}
