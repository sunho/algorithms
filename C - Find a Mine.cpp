#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll rnd(ll mn, ll mx) {
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<ll> gen(mn, mx);
  return gen(rng);
}

#ifndef ONLINE_JUDGE
struct Game {
  int n,m;
  pair<int,int> A[2];
  bool flip;
  Game(int n, int m, bool flip) : n(n), m(m), flip(flip){
    A[0] = {rnd(1,n), rnd(1,m)};
    A[1] = {rnd(1,n), rnd(1,m)};
  }
  int query(int x, int y) { 
    if (flip) swap(x,y);
    cout << "? " << x << " " << y << endl;
    assert(x <= n && y <= m);
    int d1 = abs(A[0].first-x) + abs(A[0].second-y);
    int d2 = abs(A[1].first-x) + abs(A[1].second-y);
    return min(d1,d2);
  }
  bool answer(int x, int y) { 
    if (flip) swap(x,y);
    cout << "! " << x << " " << y << endl;
    assert(x <= n && y <= m);
    return A[0] == make_pair(x,y) || A[1] == make_pair(x,y);
  }
};
#else
struct Game {
  int n,m;
  bool flip;
  Game(int n, int m, bool flip) : n(n), m(m), flip(flip) {}
  int query(int x, int y) { 
    if (flip) swap(x,y);
    cout << "? " << x << " " << y << endl;
    int d;
    cin >> d;
    return d;
  }
  bool answer(int x, int y) { 
    if (flip) swap(x,y);
    cout << "! " << x << " " << y << endl;
    return true;
  }
};
#endif


// 1          4
//
//     *
//
//          *
// 2

void solve() {
  int n,m;
  cin >> n >> m;
  Game game(n,m,n>m);
  if (n > m) swap(n,m);
  int d = game.query(1,1);
  int x1 = max(1, -m + d + 2);
  int y1 = min(m, d+1);
  int x2 = min(n, d+1);
  int y2 = max(1, -n + d + 2);
  int d2 = game.query(x1,y1);
  int d3 = game.query(x2,y2);
  int xx = min(x1 + d2/2, n);
  int yy = max(y1 - d2/2, 1);
  if (game.query(xx,yy) == 0) {
    assert(game.answer(xx, yy));
    return;
  }
  xx = max(x2 - d3/2, 1);
  yy = min(y2 + d3/2, m);
  assert(game.answer(xx,yy));
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
