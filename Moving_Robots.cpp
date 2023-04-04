#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;

  using State = array<array<long double, 8>, 8>;
  auto trans = [&](const State& state) -> State {
    State next{};
    for (int i=0;i<8;i++){
      for (int j=0;j<8;j++){
        pair<int,int> cands[] = {{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
        int cnt = 0;
        for (auto [x,y] : cands) {
          if (x < 0 || x >= 8 || y < 0 || y >= 8) {
            continue;
          }
          cnt++;
        }
         for (auto [x,y] : cands) {
          if (x < 0 || x >= 8 || y < 0 || y >= 8) {
            continue;
          }
          next[x][y] += state[i][j] / cnt;
        }
      }
    }
    return next;
  };

  long double ans = 0;

  vector<State> states;

  for (int i=0;i<8;i++){
    for (int j=0;j<8;j++){
      State state{};
      state[i][j] = 1.0l;
      for (int k=0;k<n;k++){
        state = trans(state);
      }
      states.push_back(state);
    }
  }

  State fin;
  for (int i=0;i<8;i++){
    fill(begin(fin[i]), end(fin[i]), 1.0l);
  }

  for (auto& state : states) {
    for (int i=0;i<8;i++){
      for (int j=0;j<8;j++){
        fin[i][j] *= 1.0l - state[i][j];
      }
    }
  }

  for (int i=0;i<8;i++){
    for (int j=0;j<8;j++){
      ans += fin[i][j];
    }
  }

  cout << fixed << setprecision(6) << ans << "\n";
}
