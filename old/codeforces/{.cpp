#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MOD = 998244353; // 998244353
struct mint {
  int x;
  mint(int x = 0) : x(norm(x)) { }
  mint(ll x) : x(norm(x%MOD)) { }
  int norm(int x) const { if (x < 0) { x += MOD; } if (x >= MOD) { x -= MOD; } return x; }
  mint operator+(mint o) const { return norm(x + o.x); }
  mint operator-(mint o) const { return norm(x - o.x); }
  mint operator*(mint o) const { return ll(x) * o.x; }
	mint operator/(mint o) { return *this * o.inv(); }
  mint inv() const { return exp(MOD - 2); }
	mint exp(ll n) const {
		if (!n) return mint(1);
		mint a = *this;
		mint r = a.exp(n / 2); r = r * r;
		return n&1 ? a * r : r;
	}
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  ll n;
  array<int, 6> cnt{};
  while (n%2==0) {
    cnt[2]++;
    n/=2;
  }
  while (n%3==0) {
    cnt[3]++;
    n/=3;
  }
  while (n%5==0) {
    cnt[5]++;
    n/=5;
  }
  if (n != 1) {
    cout << 0 << "\n";
    return 0;
  }
  const int m = (cnt[2]+1)*(cnt[3]+1)*(cnt[5]+1);
  
}
