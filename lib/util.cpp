// min heap
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;

// ari
ll ari(ll l, ll r) { return (l + r) * (r - l + 1) / 2; }

// ckmin ckmax
template<class T> bool ckmin(T&a, const T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T&b) { bool B = a < b; a = max(a,b); return B; }

// int128_t output
istream &operator>>(istream &is, __int128_t &v) {
  string s;
  is>>s;
  v=0;
  for(auto &it:s) if(isdigit(it)) v=v*10+it-'0';
  if(s[0]=='-') v*=-1;
  return is;
}

ostream &operator<<(ostream &os,const __int128_t &v) {
  if(v==0) return (os<<"0");
  __int128_t num=v;
  if(v<0) os<<'-',num=-num;
  string s;
  for(;num>0;num/=10) s.push_back((char)(num%10)+'0');
  reverse(begin(s),end(s));
  return (os<<s);
}

// ilog2 gcc/clang
int ilog2(ll x) { return 63 - __builtin_clzll(x); }
int ilog2(int x) { return 31 - __builtin_clz(x); }

// Order statistics tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ilog2 general
int ilog2(int x) {
  int out = 0;
  while (x >>= 1) ++out;
  return out;
}
int ilog2(ll x) {
  int out = 0;
  while (x >>= 1) ++out;
  return out;
}

// when number of distinct elements is large
// this is actually faster than hash map or binary tree map
int maxfreq(vector<int>& a) {
  int res = 0;
  int cur = 0;
  sort(a.begin(), a.end());
  for(int i=0; i < a.size(); i++) {
    if (i == 0 || a[i] == a[i-1]) {
      cur++;
      ckmax(res, cur);
    } else {
      cur = 1;
    }
  }
  return res;
}

// ternary search dobule
double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
if (f(m1) < f(m2)) {
  r = m2;
} else {
  l = m1;
}

int l = -1, r = n;
while (r - l > 1) {
  int mid = (r + l) >> 1;
  if (f(mid) > f(mid + 1))
    r = mid;
  else
    l = mid;
}
// lo + 1 is the answer

// random
ll rnd(ll mn, ll mx) {
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<ll> gen(mn, mx);
  return gen(rng);
}

vector<int> rnd_array(int n, int mn, int mx) {
  int in = 0;
  vector<int> A(n);
  int m = mx - mn + 1;
  for (int i = 0; i < m && in < n; ++i) {
    int rm = m - i;
    int rn = n - in;
    if (rnd(0, rm - 1) < rn)
      A[in++] = i;
  }
  assert(in == n);
  return A;
}

// Hash table
// For sane OJs
struct custom_hash {
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    x ^= FIXED_RANDOM;
    return x ^ (x >> 16);
  }
};

template <typename K, typename V>
using hash_map = unordered_map<K, V, custom_hash>;

// Hash table
// For codeforces
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <typename K, typename V>
using hash_map = unordered_map<K, V, custom_hash>;

// __int128 to string
string to_string(__int128 val) {
  bool neg = false;
  if (val < 0) neg = true, val = -val;
  auto high = ll(val / (__int128)1e18L);
  auto low = ll(val - (__int128)1e18L * high);
  string res;
  if (neg) res += '-';
  if (high > 0) {
    res += to_string(high);
    string temp = to_string(low);
    res += string(18u-temp.size(),'0');
    res += temp;
  } else {
    res += to_string(low);
  }
  return res;
}

