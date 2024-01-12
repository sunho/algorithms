struct trie {
  struct trie_vertex {
    array<int, 26> next;
    bool leaf = false;
    ll cnt = 0;

    trie_vertex() {
      fill(begin(next), end(next), -1);
    }
  };
  vector<trie_vertex> t;
  trie() : t(1) {}
  void add_string(const string& s) {
    int v = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (t[v].next[c] == -1) {
        t[v].next[c] = t.size();
        t.emplace_back(v, ch);
      }
      t[v].cnt++;
      v = t[v].next[c];
    }
    t[v].cnt++;
    t[v].leaf = true;
  }
};

