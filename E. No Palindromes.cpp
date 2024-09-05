#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ull = uint64_t;
#include <sys/time.h>

static int C = 0;
void init_hash() {
 while (C == 0) {
    timeval tp;
    gettimeofday(&tp, 0);
    C = (int)tp.tv_usec;
  }
}

template<int M, class B>
struct hash_int {
	int x; B b; hash_int(int x=0) : x(x), b(x) {}
	hash_int(int x, B b) : x(x), b(b) {}
	hash_int operator+(hash_int o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	hash_int operator-(hash_int o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	hash_int operator*(hash_int o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() const { return x ^ (ull) b << 21; }
	bool operator==(hash_int o) const { return (ull)*this == (ull)o; }
	bool operator<(hash_int o) const { return (ull)*this < (ull)o; }
};
using hint = hash_int<1000000007, hash_int<1000000009, unsigned>>;

struct HashInterval {
	vector<hint> ha, pw;
	HashInterval(string& str) : ha(str.size()+1), pw(ha) {
    init_hash();
		pw[0] = 1;
    for (int i=0;i<(int)str.size();i++){
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
    }
	}
	hint hash(int l, int r) {
		return ha[r + 1] - ha[l] * pw[r - l + 1];
	}
};

vector<hint> get_hashes(string& str, int length) {
  init_hash();
	if ((int)str.size() < length) return {};
	hint h = 0, pw = 1;
  for (int i=0;i<length;i++)
		h = h * C + str[i], pw = pw * C;
	vector<hint> ret = {h};
  for (int i=length;i<(int)str.size();i++) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

hint hash_string(string& s){
  init_hash();
  hint h{}; 
  for(char c:s) 
    h=h*C+c;
  return h;
}

void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  HashInterval hash(s);
  string rs = s;
  reverse(begin(rs),end(rs));
  HashInterval hash_r(rs);
  auto is_palin = [&](int l, int r) {
    int m = (l+r)/2;
    return hash.hash(l, r) == hash_r.hash(n-1-r,n-1-l);
  };
  if (rs != s) {
    cout << "YES" << "\n";
    cout << 1 << "\n";
    cout << s << "\n";
    return;
  }
  if (s == string(n,s[0])) {
    cout << "NO" << "\n";
    return;
  }
  for (int i=0;i<n/2;i++){
    if (!is_palin(0,i) && !is_palin(i+1,n-1)) {
      cout << "YES" << "\n";
      cout << 2 << "\n";
      cout << s.substr(0,i+1) << " " << s.substr(i+1) << "\n";
      return;
    }
  }
  cout << "NO" << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
