int ilog2(int n) {
  int res = 0;
  while (n >>= 1) res++;
  return res;
}

const int WN = 1 << 20;
mint w[WN];
void init_w() {
  w[WN / 2] = 1;
  mint g = mint(3).pow(MOD / WN);
  for (int i = WN / 2 + 1; i < WN; ++i) w[i] = w[i - 1] * g;
  for (int i = WN / 2 - 1; i > 0; --i) w[i] = w[i << 1];
}

void ntt(vector<mint>& a) {
  int m = a.size();
  for (int l = m / 2; l; l /= 2) {
    for (int i = 0; i < m; i += l * 2) {
      for (int j = 0; j < l; j++) {
        mint x = a[i + j], y = a[i + j + l];
        a[i + j + l] = (x - y) * w[j + l];
        a[i + j] = x + y;
      }
    }
  }
}

void intt(vector<mint>& a) { 
  int m = a.size();
  for (int l = 1; l < m; l *= 2) {
    for (int i = 0; i < m; i += l * 2) {
      for (int j = 0; j < l; j++) {
        mint x = a[i + j];
        mint y = w[j + l] * a[i + j + l];
        a[i + j] = x + y, a[i + j + l] = x - y;
      }
    }
  }

  mint inv = mint(m).inv();
  for (mint& v : a) v *= inv;
  reverse(a.begin()+1,a.end());
}

vector<mint> poly_mul(const vector<mint>& a, const vector<mint>& b) {
  const int n = a.size()+b.size()-1;
  const int m = 2 << ilog2(n);
  vector<mint> a2(m), b2(m);
  copy(a.begin(), a.end(), a2.begin());
  copy(b.begin(), b.end(), b2.begin());
  ntt(a2), ntt(b2);
  for (int i=0;i<m;i++) a2[i] *= b2[i];
  intt(a2);
  a2.resize(n);
  return a2;
}