#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
using ll = long long;

using ld = float;
using cd = complex<ld>;
const double PI = acos(-1);

int ilog2(int n) {
  int res = 0;
  while (n >>= 1) res++;
  return res;
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}


vector<cd> poly_mul(const vector<cd>& a, const vector<cd>& b) {
  const int n = a.size()+b.size()-1;
  const int m = 2 << ilog2(n);
  vector<cd> a2(m), b2(m);
  copy(a.begin(), a.end(), a2.begin());
  copy(b.begin(), b.end(), b2.begin());
  fft(a2, false);
  fft(b2, false);
  for (int i=0;i<m;i++) a2[i] *= b2[i];
  fft(a2, true);
  a2.resize(n);
  return a2;
}

void solve() {
  int n;
  int m,q;
  cin >> n >> m >> q;
  ll sum = 0;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    sum += A[i];
  }
  vector<cd> P(n+1);
  for (int i=0;i<n;i++){
    P[i+1] = cd(A[i]/(ld)sum,0);
  }
  vector<cd> res(1);
  res[0] = cd(1,0);
  while (m) {
    if (m&1) res = poly_mul(P,res);
    P = poly_mul(P, P);
    m /= 2;
  }
  vector<ld> pf(res.size()+1);
  for (int i=0;i<res.size();i++){
    pf[i+1] = pf[i] + res[i].real();
  }
  for (int i=0;i<q;i++){
    int x;
    cin >> x;
    cout << fixed << setprecision(15)<< pf[x+1] << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
