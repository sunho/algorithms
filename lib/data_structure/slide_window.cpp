struct slide_window {
  deque<pair<int,int>> q;
  int l = 0, r = 0;
  slide_window() = default;
  void add(int x) {
    while (!q.empty() && q.back().first <= x) {
      q.pop_back();
    }
    q.push_back({x,r});
    ++r;
  }
  void remove() {
    if (q.front().second == l) q.pop_front();
    ++l;
  }
  int query() {
    return q.empty() ? -inf : q.front().first;
  }
  size_t size() { return r-l; }
};
