#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int P = 998244353; // 1000000007
struct zint {
  int x;
  int norm(int x) const { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  zint(int x = 0) : x(norm(x)) {}
  zint(ll x) : x(norm(x % P)) {}
  zint pow(int x) {
    zint res = 1;
    zint a = *this;
    while (x) {
      if (x % 2)
        res = res * a;
      a = a * a;
      x /= 2;
    }
    return res;
  }
  int val() const { return x; }
  #define OP(OO) friend zint operator OO(const zint& lhs, const zint& rhs) { return ((ll)lhs.x OO rhs.x) % P; }
  OP(*)
  OP(+)
  OP(-)
};

using matrix = array<array<zint,4>,4>;

matrix matmul(const matrix& A, const matrix& B) {
  matrix res{};
  for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
      for (int k=0;k<4;k++){
        res[i][j] = res[i][j] + A[i][k]*B[k][j]; 
      }
    }
  }
  return res;
}

matrix matpow(matrix A, int x) {
  matrix res{};
  res[0][0] = 1;
  res[1][1] = 1;
  res[2][2] = 1;
  res[3][3] = 1;
  while (x) {
    if (x%2)
      res = matmul(res, A);
    A = matmul(A,A);
    x /= 2;
  }
  return res;
}

array<zint, 4> matdot(matrix A, array<zint, 4> vec) {
  array<zint, 4> res{};
  for (int i=0;i<4;i++){
    for (int j=0;j<4;j++) {
      res[i] = res[i] + A[i][j] * vec[j];
    }
  }
  return res;
}

zint calc_sum(array<zint, 3> state, int n) {
  matrix T ={{
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1}
 }};
  auto res = matdot(matpow(T, n), {0, state[0], state[1], state[2]});
  return res[0];
}

array<zint, 3> calc_state(array<zint, 3> state, int n) {
  matrix T {{
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1}
  }};
  auto res = matdot(matpow(T, n), {0, state[0], state[1], state[2]});
  return {res[1],res[2],res[3]};
}

struct SegTree {
  int n;
  vector<zint> t;
  vector<array<zint, 3>> lazy;
  SegTree(int n) : n(n), t(4*n), lazy(4*n) {}

  void push(int v, int l, int r) {
    int tm = (l+r)/2;
    zint L = calc_sum(lazy[v], tm-l+1);
    zint R = calc_sum(lazy[v], r-l+1);
    t[v*2] = t[v*2]+L;
    t[v*2+1] = t[v*2+1]+R-L;
    lazy[v*2] = lazy[v];
    lazy[v*2+1] = calc_state(lazy[v], tm-l+1);
    lazy[v] = {0,0,0};
  }
  
  void update(int l, int r, int start, zint a, int v = 1, int tl = 0, int tr = -1) {
    if (tr == -1) tr = n-1;
    if (l > r) return;
    if (l == tl && r == tr) {
      array<zint,3> init = {{a*((ll)(l-start+2)*(l-start+1)/2),a*(l-start+2),a}};
      t[v] = t[v] + calc_sum(init, r-l+1);
      lazy[v][0] = lazy[v][0] + init[0];
      lazy[v][1] = lazy[v][1] + init[1];
      lazy[v][2] = lazy[v][2] + init[2];
    } else {
      int tm = (tl+tr)/2;
      push(v, tl, tr);
      update(l, min(tm,r), start, a, v*2, tl, tm);
      update(max(l,tm+1), r, start, a, v*2+1, tm+1, tr);
    }
  }

  zint get(int pos, int v = 1, int tl = 0, int tr = -1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      return t[v];
    }
    push(v, tl, tr);
    int tm = (tl+tr)/2;
    if (pos <= tm) {
      return get(pos, v*2, tl, tm);
    } else {
      return get(pos, v*2+1, tm+1, tr);
    }
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  SegTree st(n);
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
    st.update(i,n-1,i,A[i]);
  }

  while(q--) {
    int t;
    cin >> t;
    if (t==1) {
      int i,x;
      cin >> i >> x;
      --i;
      zint delta = (zint)x - A[i];
      st.update(i,n-1,i,delta);
    } else {
      int x; 
      cin >> x;
      --x;
      cout << st.get(x).val() << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);

  solve();

  return 0;
}

