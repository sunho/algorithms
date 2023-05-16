#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353; // 998244353
struct mint {
  int x;
  constexpr inline mint(int x = 0) : x(x) { }
  constexpr inline mint operator+(mint o) const { return x + o.x < MOD ? x + o.x : x + o.x - MOD; }
  constexpr inline mint operator-(mint o) const { return x - o.x < 0 ? x - o.x + MOD : x - o.x; }
  constexpr inline mint operator*(mint o) const { return int(ll(x) * o.x % MOD); }
  constexpr inline mint &operator+=(mint o) { return *this = *this + o; }
  constexpr inline mint &operator-=(mint o) { return *this = *this - o; }
  constexpr inline mint &operator*=(mint o) { return *this = *this * o; }
  constexpr inline mint inv() const { return pow(MOD - 2); }
  constexpr inline mint pow(ll x) const {
    mint a = *this;
    mint b = 1;
    for (; x; x >>= 1) {
      if (x & 1)
        b *= a;
      a *= a;
    }
    return b;
  }
};

int ilog2(int n) {
  int res = 0;
  while (n >>= 1) res++;
  return res;
}

const int NN = 1 << 20;
mint w[NN];
void init_w() {
    w[NN / 2] = 1;
    const mint g = mint(3).pow(MOD / NN);
    for (int i = NN / 2 + 1; i < NN; ++i) w[i] = w[i - 1] * g;
    for (int i = NN / 2 - 1; i > 0; --i) w[i] = w[i << 1];
}

void fft(vector<mint>& a) {
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

void ifft(vector<mint>& a) { 
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  init_w();

  int n,m;
  cin >> n >> m;

  const int M = 2 << ilog2(n+m-1);

  vector<mint> A(M), B(M);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    A[i] = a;
  }
  for (int i=0;i<m;i++){
    int b;
    cin >> b;
    B[i] = b;
  }
  // reverse(B.begin(), B.begin()+m);
  fft(A), fft(B);
  for (int i=0;i<M;i++){
    A[i] *= B[i];
  }
  ifft(A);
  for (int i=0;i<n+m-1;i++){
    cout << A[i].x << " ";
  }
  cout << "\n";
}
