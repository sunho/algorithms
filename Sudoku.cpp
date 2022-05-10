#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  vector<vector<char>> A(9, vector<char>(9));
  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++) {
      cin >> A[i][j];
    }
  }

  auto full_avail = bitset<10>().set();
  full_avail.reset(0);
  vector<vector<bitset<10>>> grid_avail(3, vector<bitset<10>>(3,full_avail));
  vector<bitset<10>> row_avail(9, full_avail);
  vector<bitset<10>> col_avail(9, full_avail);
  
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      for(int k=0;k<3;k++) {
        for (int z=0;z<3;z++) {
          grid_avail[i][j].reset(A[i*3+k][j*3+z]-'0');
        }
      }
    }
  }
  for (int i=0;i<9;i++) {
    for (int j=0;j<9;j++) {
      row_avail[i].reset(A[i][j]-'0');
      col_avail[j].reset(A[i][j]-'0');
    }
  }

  auto go = [&](int i, int j, auto&& self) {
    if (i == 9) {
      return true;
    }
    if (j == 9) {
      return self(i+1, 0, self);
    }
    if (A[i][j] != '0') {
      return self(i, j+1, self);
    }
    int r = i / 3;
    int c = j / 3;
    auto avail = grid_avail[r][c] & row_avail[i] & col_avail[j];
    if (!avail.any()) {
      return false;
    }
    for(int k=0;k<10;k++){
      if (avail[k]) {
        A[i][j] = '0' + (char)k;
        grid_avail[r][c].reset(k);
        row_avail[i].reset(k);
        col_avail[j].reset(k);
        if (self(i, j+1, self)) {
          return true;
        }
        grid_avail[r][c].set(k);
        row_avail[i].set(k);
        col_avail[j].set(k);
        A[i][j] = '0';
      }
    }
    return false;
  };

  go(0,0,go);

  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++) {
      cout << A[i][j];
    }
    cout << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
