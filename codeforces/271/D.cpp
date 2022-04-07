#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int rand_int(int n) {
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<int>(0, n)(rng);
}
using ull = unsigned long long;
const int MM = 1000000007;
const int MM2 = 1000000009;
struct PolyHash {
  template<int M, class B>
  struct g_zint_2 {
    int x; B b; g_zint_2(int x=0) : x(x), b(x) {}
    g_zint_2(int x, B b) : x(x), b(b) {}
    g_zint_2 operator+(g_zint_2 o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
    g_zint_2 operator-(g_zint_2 o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
    g_zint_2 operator*(g_zint_2 o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
    explicit operator ull() const { return x ^ (ull) b << 21; }
    ull val() const { return (ull)*this; }
  };
  using hint = g_zint_2<MM, g_zint_2<MM2, unsigned>>;
  static int base;
	vector<hint> ha, pw;
	PolyHash(string& str) : ha(str.size()+1), pw(ha) {
		pw[0] = 1;
		for(int i=0;i<str.size();i++)
			ha[i+1] = ha[i] * base + str[i],
			pw[i+1] = pw[i] * base;
	}
	hint operator()(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
  static vector<hint> getHashes(string& str, int length) {
    if (str.size() < length) return {};
    hint h = 0, pw = 1;
    for(int i=0;i<length;i++)
      h = h * PolyHash::base + str[i], pw = pw * PolyHash::base;
    vector<hint> ret = {h};
    for(int i=length;i<str.size();i++) {
      ret.push_back(h = h * PolyHash::base + str[i] - pw * str[i-length]);
    }
    return ret;
  }
  static hint hashString(string& s){hint h{}; for(char c:s) h=h*PolyHash::base+c;return h;}
};
int PolyHash::base(rand_int(MM));

void solve() {
  string S;
  cin >> S;
  string B;
  cin >> B;
  int k;
  cin >> k;
  PolyHash hash(S);
  vector<ll> V;
  int ans = 0;
  for(int i=0;i<S.size();i++) {
    int nk = k+1;
    for(int j=i;j<S.size();j++) {
      if (B[S[j]-'a'] == '0') nk--;
      if (nk == 0) {
        break;
      }
      V.push_back(hash(i, j+1).val());
    }
  }
  sort(all(V));
  V.resize(unique(all(V)) - all(V)-V.begin());
  cout << V.size() << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
