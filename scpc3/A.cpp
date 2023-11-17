#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool move_state(pair<int,int>& state, int step) {
  state.second -= step;
  if (state.second < 0) {
    state = {0,20};
    return true;
  }
  if (state.first == 0 && state.second == 15) {
    state.first = 1;
    state.second = 11;
    return false;
  }
  if (state.first == 0 && state.second == 10) {
    state.first = 1;
    state.second = 6;
    return false;
  }
  if (state.first == 1 && state.second == 8) {
    state.first = 2;
    state.second = 3;
    return false;
  }
  return false;
}

void solve() {
  pair<int,int> state = {0,20};
  vector<vector<int>> cnt_cache(3, vector<int>(21, -1));
  vector<vector<int>> k_cache(3, vector<int>(21, -1));
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  ll cnt = 0;
  for (int i=0;i<n;i++)
    cin >> A[i];
  while (k--) {
    auto [x,y] = state;
    if (cnt_cache[x][y] != -1) {
      int diff = k - k_cache[x][y];
      int cnt_diff = cnt_cache[x][y] - cnt;
      cnt += (ll)cnt_diff*(k/diff);
      k %= diff;
      cnt_cache.assign(3, vector<int>(21,-1));
      k_cache.assign(3, vector<int>(21,-1));
    } else {
      cnt_cache[x][y] = cnt;
      k_cache[x][y] = k;
    }
    for (int i=0;i<n;i++){
      if (move_state(state, A[i]))
        cnt ++;
    }
  }
  cout << cnt << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t=0;t<T;t++){
    cout << "Case #" << t+1 << "\n";
    solve();
  }
}
