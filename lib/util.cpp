// Debug
#ifdef LOCAL
freopen("input.txt", "r" , stdin);
freopen("output.txt", "w", stdout);
#endif

#define dbg(x) "(" << #x <<": " << (x) << ") "
template<typename Ostream, typename Cont>
enable_if_t<is_same_v<Ostream,ostream>, Ostream&> 
operator<<(Ostream& os, const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename ...Ts>
ostream& operator<<(ostream& os, const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
ostream& operator<<(ostream& os, mint p){
	return os<<p.val();
}

// Order statistics tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;

// Hash table
// For sane OJs
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

template<typename K, typename V>
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
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template<typename K, typename V>
using hash_map = unordered_map<K, V, custom_hash>;

void print(__int128 x) {
  if (x < 0) {
    cout<<'-';
    x = -x;
  }
  if (x > 9) print(x / 10);
  cout<<(int)(x % 10);
}
