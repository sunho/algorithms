#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int cnt = 0;
  for(int i=1000;i<=1999;i++){
    for(int j=i+1;j<=1999;j++) {
      int a1 = i / 100 % 10;
      int a2 = j / 100 % 10;
      int b1 = i / 10 % 10;
      int b2 = j / 10 % 10;
      int c1 = i % 10;
      int c2 = j % 10;
      if (a1 + a2 > 9) continue;
      if (b1 + b2 > 9) continue;
      if (c1 + c2 > 9) continue;
      cnt ++;
    }
  }
  // for(int i=0;i<=9;i++){
  //   for(int j=0;j<=9;j++){
  //     // if(i>=j) continue;
  //     if (i+j<=9) cnt++;
  //   }
  // }
  cout << cnt << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
