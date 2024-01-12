const int inf = 1e9;
template <typename Info> struct seg_tree {
  int n, m;
  vector<vector<Info>> info;
  seg_tree(int n, int m) : n(n), m(m), info(4 * n, vector(4 * m, Info())) {}
  seg_tree(int n, int m, vector<vector<Info>> A)
      : n(n), m(m), info(4 * n, vector(4 * m, Info())) {
    build_x(1, 0, n - 1, A);
  }
  void build_y(int vx, int lx, int rx, int vy, int ly, int ry,
               const vector<vector<Info>> &A) {
    if (ly == ry) {
      if (lx == rx)
        info[vx][vy] = A[lx][ly];
      else
        info[vx][vy] = Info::combine_x(info[vx * 2][vy], info[vx * 2 + 1][vy]);
    } else {
      int my = (ly + ry) / 2;
      build_y(vx, lx, rx, vy * 2, ly, my, A);
      build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, A);
      info[vx][vy] = Info::combine_x(info[vx][vy * 2], info[vx][vy * 2 + 1]);
    }
  }
  void build_x(int vx, int lx, int rx, const vector<vector<Info>> &A) {
    if (lx != rx) {
      int mx = (lx + rx) / 2;
      build_x(vx * 2, lx, mx, A);
      build_x(vx * 2 + 1, mx + 1, rx, A);
    }
    build_y(vx, lx, rx, 1, 0, m - 1, A);
  }
  void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y,
                const Info &val) {
    if (ly == ry) {
      if (lx == rx) {
        info[vx][vy] = val;
      } else {
        info[vx][vy] = Info::combine_x(info[vx * 2][vy], info[vx * 2 + 1][vy]);
      }
      return;
    }
    int my = (ly + ry) / 2;
    if (y <= my)
      update_y(vx, lx, rx, vy * 2, ly, my, x, y, val);
    else
      update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, val);
    info[vx][vy] = Info::combine_y(info[vx][vy * 2], info[vx][vy * 2 + 1]);
  }
  void update_x(int vx, int lx, int rx, int x, int y, const Info &val) {
    if (lx != rx) {
      int mx = (lx + rx) / 2;
      if (x <= mx)
        update_x(vx * 2, lx, mx, x, y, val);
      else
        update_x(vx * 2 + 1, mx + 1, rx, x, y, val);
    }
    update_y(vx, lx, rx, 1, 0, m - 1, x, y, val);
  }
  void update(int x, int y, const Info &val) {
    update_x(1, 0, n - 1, x, y, val);
  }
  Info query_y(int vx, int vy, int l, int r, int x, int y) {
    if (l > y || r < x)
      return Info();
    if (l >= x && r <= y)
      return info[vx][vy];
    int my = (l + r) / 2;
    return Info::combine_y(query_y(vx, 2 * vy, l, my, x, y),
                           query_y(vx, 2 * vy + 1, my + 1, r, x, y));
  }
  Info query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (tlx > rx || trx < lx)
      return Info();
    if (tlx >= lx && trx <= rx)
      return query_y(vx, 1, 0, m - 1, ly, ry);
    int mx = (tlx + trx) / 2;
    return Info::combine_x(query_x(2 * vx, tlx, mx, lx, rx, ly, ry),
                           query_x(2 * vx + 1, mx + 1, trx, lx, rx, ly, ry));
  }
  Info query(int lx, int rx, int ly, int ry) {
    return query_x(1, 0, n - 1, lx, rx, ly, ry);
  }
};

struct node {
  ll val = 0;
  static node combine_x(node lhs, node rhs) { return {lhs.val + rhs.val}; }
  static node combine_y(node lhs, node rhs) { return {lhs.val + rhs.val}; }
};
