#include <array>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto encode = [](array<int, 9> state) {
    int res = 0;
    for (int i=0;i<9;i++){
      res *= 9;
      res += state[i];
    }
    return res;
  };
  auto decode = [](int state) {
    array<int, 9> res{};
    for (int i=8;i>=0;i--){
      res[i] = state % 9;
      state /= 9;
    }
    return res;
  };

  hash_map<int, int> dist;
  dist[encode({0,1,2,3,4,5,6,7,8})]=0;
  queue<int> q;
  q.push(encode({0,1,2,3,4,5,6,7,8}));
  vector<pair<int,int>> pos;
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      pair<int,int> cands[] = {{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
      for (auto [x,y] : cands) {
        if (x < 0 || x >= 3 || y < 0 || y >= 3) continue;
        pair<int,int> a = {i,j};
        pair<int,int> b = {x,y};
        if (a > b) swap(a,b);
        pos.push_back({a.first*3+a.second,b.first*3+b.second});
      }
    }
  }
  sort(pos.begin(), pos.end());
  pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
  while (!q.empty()) {
    auto state = decode(q.front());
    int u = encode(state);
    q.pop();
    for (auto [a,b] : pos) {
      swap(state[a], state[b]);
      int v = encode(state);
      swap(state[a], state[b]);
      if (!dist.count(v)) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  array<int, 9> state{};
  for (int i=0;i<9;i++){
    cin >> state[i];
    --state[i];
  }
  cout << dist[encode(state)] << "\n";
}
