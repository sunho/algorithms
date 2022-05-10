// ilog2 gcc/clang
int ilog2(ll x) { return 63 - __builtin_clzll(x); }
int ilog2(int x) { return 31 - __builtin_clz(x); }

// ilog2
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

template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template<class K, class V> using hash_table = gp_hash_table<K, V, custom_hash>;