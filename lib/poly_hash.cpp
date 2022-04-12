int rand_int(int n) {
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<int>(0, n)(rng);
}
using ull = unsigned long long;
const int MM = 1000000007;
const int MM2 = 1000000009;
struct poly_hash {
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
  poly_hash(string& str) : ha(str.size()+1), pw(ha) {
    pw[0] = 1;
    for(int i=0;i<str.size();i++)
      ha[i+1] = ha[i] * base + str[i],
      pw[i+1] = pw[i] * base;
    }
    hint operator()(int a, int b) { // hash [a, b)
    return ha[b] - ha[a] * pw[b - a];
  }
  static vector<hint> get_hashes(string& str, int length) {
    if (str.size() < length) return {};
    hint h = 0, pw = 1;
    for(int i=0;i<length;i++)
      h = h * poly_hash::base + str[i], pw = pw * poly_hash::base;
    vector<hint> ret = {h};
    for(int i=length;i<str.size();i++) {
      ret.push_back(h = h * poly_hash::base + str[i] - pw * str[i-length]);
    }
    return ret;
  }
  static hint hash_string(string& s){hint h{}; for(char c:s) h=h*poly_hash::base+c;return h;}
};
int poly_hash::base(rand_int(MM));
