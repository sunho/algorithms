#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007; // 998244353
struct mint {
  int v;
  mint() : v(0) {}
  mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint operator+(mint a, mint b) { return a += b; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  sort(begin(A),end(A));
  mint off = 0;
  for (int k=n;k>=2;k--){
    off = off * 2;
    off += 2*A[0];
    ll mn = A[0];
    for (int i=0;i<k;i++){
      A[i] -= mn;
    }
    if (k == 2) {
      cout << (off + A[0] + A[1]).v;
      return 0;
    }
    vector<ll> next;
    int l=0, li=1, r=1, ri=2;
    while (next.size() < k-1) {
      if (A[l] + A[li] <= A[r] + A[ri]) {
        next.push_back(A[l]+A[li]);
        li++;
        if (li == k) {
          int rr = r;
          li = r, li = ri;
          r = rr+1, ri = r+1;
        }
      } else {
        next.push_back(A[r]+A[ri]);
        ri++;
      }
    }
    A = move(next);
  }

}
