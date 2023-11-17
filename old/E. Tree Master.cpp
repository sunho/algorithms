#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename K, typename V>
using hash_map = gp_hash_table<K, V, custom_hash>;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> p(n);
  p[0] = -1;
  for (int i=1;i<n;i++){
    cin >> p[i];
    p[i]--;
  }
  auto combine = [](int x, int y) {
    return ((ll)x<<32) | (ll)y;
  };
  hash_map<ll, ll> cache;
  while (q--){
    int x,y;
    cin >> x >> y;
    --x,--y;
    if (x>y) swap(x,y);
    vector<pair<pair<int,int>,ll>> pend;
    ll cnt = 0;
    while (x != -1) {
      if (x>y) swap(x,y);
      if (cache.find(combine(x,y)) != cache.end()) {
        cnt = cache[combine(x,y)];
        break;
      }
      pend.push_back({{x,y}, (ll)A[x] * A[y]});
      x = p[x];
      y = p[y];
    }
    reverse(begin(pend),end(pend));
    for (int i=0;i<pend.size();i++){
      cnt += pend[i].second;
      auto [x,y] = pend[i].first;
      if (i > sqrt(n))
        cache[combine(x,y)] = cnt;
    }
    cout << cnt << "\n";
  }
}
