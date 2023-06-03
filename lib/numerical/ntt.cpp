int ilog2(int n) {
  int res = 0;
  while (n >>= 1) res++;
  return res;
}

void fft(mint* a, int m, mint omega) {
  if (m == 1) return;
  fft(a, m/2,omega*omega);
  fft(a+m/2,m/2,omega*omega);
  mint cur = 1;
  for (int i=0;i<m/2;i++,cur*=omega){
    mint even = a[i], odd = a[i+m/2];
    a[i] = even + cur * odd;
    a[i+m/2] = even - cur * odd;
  }
}

void fft(vector<mint>& a, bool inv) {
  const int m = a.size();
  for (int i=1,j=0;i<m;i++){
    int bit = m >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  mint omega = pow(mint(3), (MOD-1)/m);
  fft(a.data(),m,omega);
  if (inv) {
    mint minv = mint(m).inv();
    reverse(a.begin()+1,a.end());
    for (mint& v : a) v *= minv;
  }
}
