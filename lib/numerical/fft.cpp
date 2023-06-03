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
