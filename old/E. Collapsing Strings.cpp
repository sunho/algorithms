#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// full

struct trie_vertex {
  array<int, 26> next;
  bool leaf = false;
  int p = -1;
  ll sum = 0;
  ll cnt = 0;
  char pch;

  trie_vertex(int p=-1, char ch='$') : p(p), pch(ch) {
    fill(begin(next), end(next), -1);
  }
};

vector<trie_vertex> t(1);

void add_string(const string& s) {
  int v = 0;
  for (char ch : s) {
    int c = ch - 'a';
    if (t[v].next[c] == -1) {
      t[v].next[c] = t.size();
      t.emplace_back(v, ch);
    }
    t[v].sum += s.size();
    t[v].cnt++;
    v = t[v].next[c];
  }
  t[v].cnt++;
  t[v].sum += s.size();
  t[v].leaf = true;
}

void solve() {
  int n;
  cin >> n;
  vector<string> A;
  for (int i=0;i<n;i++){
    string s;
    cin >> s;
    A.push_back(s);
    add_string(s);
  }
  ll ans = 0;
  for (int i=0;i<n;i++){
    int cur = 0;
    string tt = A[i];
    reverse(begin(tt),end(tt));
    for (int j=0;j<tt.size();j++){
      int nxt = t[cur].next[tt[j]-'a'];
      if (nxt == -1)  {
        ans += t[cur].sum + (t[cur].cnt)*(A[i].size()-2*j);
        cur = nxt;
        break;
      }
      ans += (t[cur].sum-t[nxt].sum) + (t[cur].cnt - t[nxt].cnt)*(A[i].size()-2*j);
      cur = nxt;
    }
    if (cur != -1) {
      ans += t[cur].sum - (t[cur].cnt)*(A[i].size());
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
