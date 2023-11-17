#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using cd = complex<ld>;

const ld PI = acosl(-1);

int ilog2(int n) {
  int res = 0;
  while (n >>= 1) res++;
  return res;
}

void fft(cd* a, int m) {
  if (m == 1) return;
  fft(a, m/2);
  fft(a+m/2,m/2);
  cd omega = {cosl(2*PI/m), sinl(2*PI/m)};
  cd cur = {1,0};
  for (int i=0;i<m/2;i++,cur*=omega){
    cd even = a[i], odd = a[i+m/2];
    a[i] = even + cur*odd;
    a[i+m/2] = even - cur * odd;
  }
}

void fft(vector<cd>& a, bool inv) {
  const int m = a.size();
  for (int i=1,j=0;i<m;i++){
    int bit = m >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  fft(a.data(),m);
  if (inv) {
    reverse(a.begin()+1,a.end());
    for (cd& v : a) v = {roundl(v.real()/m),0};
  }
}

vector<cd> poly_mul(const vector<int>& a, const vector<int>& b) {
  const int n = a.size()+b.size()-1;
  const int m = 2 << ilog2(n);
  vector<cd> a2(m), b2(m);
  copy(a.begin(), a.end(), a2.begin());
  copy(b.begin(), b.end(), b2.begin());
  fft(a2, false), fft(b2, false);
  for (int i=0;i<m;i++) a2[i] *= b2[i];
  fft(a2, true);
  a2.resize(n);
  return a2;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<n;i++) {
    A.push_back(A[i]);
  }
  vector<int> B(n);
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  reverse(begin(B),end(B));
  auto res = poly_mul(A,B);
  int ans = 0;
  for (int i=n-1;i<2*n-1;i++){
    ans = max(ans,(int)res[i].real());
  }
  cout << ans << "\n";
}

