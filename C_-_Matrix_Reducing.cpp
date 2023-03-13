#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int h1,w1,h2,w2;
  cin >> h1 >> w1;
  vector<vector<int>> A(h1, vector<int>(w1));
  for (int i=0;i<h1;i++){
    for(int j=0;j<w1;j++){
      cin >> A[i][j];
    }
  }
  cin >> h2 >> w2;
  vector<vector<int>> B(h2, vector<int>(w2));
  for(int i=0;i<h2;i++){
    for(int j=0;j<w2;j++){
      cin >> B[i][j];
    }
  }
  for (int mask1=1;mask1<(1<<h1);mask1++){
    for (int mask2=1;mask2<(1<<w1);mask2++){
      if (__builtin_popcount(mask1) != h2 || 
        __builtin_popcount(mask2) != w2)
        continue;
      bool ok = true;
      int ii = 0;
      for (int i=0;i<h1;i++){
        if (mask1 & (1 << i)) {
          int jj = 0;
          for(int j=0;j<w1;j++){
            if (mask2 & (1 << j)) {
              if (A[i][j] != B[ii][jj]) {
                ok = false;
              }
              jj++;
            }
          }
          ii++;
        }
      }
      if (ok){
        cout << "Yes" << "\n";
        return;
      }
    }
  }
  cout << "No" << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
