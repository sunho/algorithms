// minimal
struct trie_vertex {
  array<int, 26> next;
  bool leaf = false;
  trie_vertex() {
    fill(begin(next), end(next), -1);
  }
};
vector<trie_vertex> trie(1);

// full
struct string_trie {
  vector<trie_vertex> t(1);

  struct trie_vertex {
    array<int, 26> next;
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    array<int, 26> go;

    trie_vertex(int p=-1, char ch='$') : p(p), pch(ch) {
      fill(begin(next), end(next), -1);
      fill(begin(go), end(go), -1);
    }
  };

  void add_string(const string& s) {
    int v = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (t[v].next[c] == -1) {
        t[v].next[c] = t.size();
        t.emplace_back(v, ch);
      }
      v = t[v].next[c];
    }
    t[v].leaf = true;
  }

  int get_link(int v) {
    if (t[v].link == -1) {
      if (v == 0 || t[v].p == 0)
        t[v].link = 0;
      else
        t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
  }

  int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
      if (t[v].next[c] != -1)
        t[v].go[c] = t[v].next[c];
      else
        t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
  }
};
