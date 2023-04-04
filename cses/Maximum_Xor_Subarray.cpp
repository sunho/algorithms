#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct trie_node {
  trie_node() = default;
  int cnt = 0;
  array<int, 2> next{-1,-1};  
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;

  vector<trie_node> T(32*n+128);
  int id = 0;
  T[id++].cnt = 0;
  vector<int> A(n);
  for (int i=0;i<n;i++)
    cin >> A[i];
  vector<int> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] ^ A[i];
  }
  for (int i=0;i<=n;i++){
    trie_node* cur = &T[0];
    for (int j=30;j>=0;j--){
      int nxt = (bool)(pf[i] & (1<<j));
      if (cur->next[nxt] == -1) {
        cur->next[nxt] = id++;
      }
      cur->cnt++;
      cur = &T[cur->next[nxt]];
    }
    cur->cnt++;
  }
  int ans = 0;
  for (int i=0;i<=n;i++){
    trie_node* cur = &T[0];
    int cand = 0;
    for (int j=30;j>=0;j--){
      int nxt = (bool)(pf[i] & (1<<j));
      nxt^=1;
      if (cur->next[nxt] == -1) {
        nxt^=1;
      }
      cur = &T[cur->next[nxt]];
      cand |= (nxt) << j;
    }
    ans = max(cand^pf[i], ans);
  }
  cout << ans << "\n";
}
