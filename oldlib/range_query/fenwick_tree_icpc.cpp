struct fenwick_tree {
  vector<ll> sums;
  fenwick_tree(int n) : sums(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < (int)sums.size(); pos |= pos + 1) 
      sums[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos]
    ll res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) 
      res += sums[pos];
    return res;
  }
  ll query(int l, int r) { // sum of values in [l, r]
    return query(r) - query(l-1);
  }
};
