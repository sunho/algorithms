#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct seg_tree {
  seg_tree(int n, int bias=0) : n(n), bias(bias), a(n*4) {
  }
  seg_tree(vector<int>&v) : n(v.size()), bias(0), a(n*4) {
    build(0, n - 1, 1, v);
  }
  struct node {
    int gcd = 0;
  };
  node merge(const node &x, const node &y) {
    node ret;
    ret.gcd = gcd(x.gcd, y.gcd);
    return ret;
  }
  void build(int l, int r, int rt, vector<int>& v) {
    if(l == r) {
      a[rt].gcd = v[l];
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt*2,v);
    build(m + 1, r, rt*2+1,v);
    a[rt] = merge(a[rt*2], a[rt*2+1]);
  }
  node query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return a[rt];
    node ret;
    int m = (l + r) / 2;
    if(L <= m) ret = merge(ret, query(L, R, l, m, rt*2));
    if(m < R) ret = merge(ret, query(L, R, m+1, r, rt*2+1));
    return ret;
  }
  int query(int L, int R) {
    L += bias, R += bias;
    return query(L, R-1, 0, n - 1, 1).gcd;
  }

  int n;
  int bias;
  vector<node> a;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
 
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    seg_tree ST(A);
 
 
    int cnt = 0;
    int of = 0;
    for(int i=0;i<n;i++) {
        if (A[i] == 1) {
            ++cnt;
            of = i+1;
        } else {
            if (of != i) {
                int l = of-1;
                int r = i+1;
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    int dl = i - mid + 1;
                    if (ST.query(mid,i+1) >= dl) r = mid;
                    else l = mid;
                }
 
                int dl = i - r + 1;
                if (ST.query(r, i+1) == dl) {
                    ++cnt;
                    of = i+1;
                }
            }
        }
        cout << cnt << ' ';
    }
    cout << '\n';
 
    return 0;
}