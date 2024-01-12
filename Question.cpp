#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1<<12;
vector<int> E(1);

void solve1() {
  int n,t;
  cin >> n >> t;
  for (int i=0;i<t;i++) {
    int x,y;
    cin >> x >> y;
    for (int z=0;z<12;z++) {
      if ((E[x]>>z&1) && !(E[y]>>z&1)) {
        cout << z + 1 << "\n";
        break;
      }
    }
  }
}

void solve2() {
  int n,t;
  cin >> n >> t;
  for (int i=0;i<t;i++){
    int q,h; 
    cin >> q >> h;
    if (E[q] >> (h-1) & 1) {
      cout << "yes" << "\n";
    } else {
      cout << "no" << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int i=1;i<N;i++){
    if (__builtin_popcount(i) == 6) {
      E.push_back(i);
    }
  }
  int t;
  cin >> t;
  if (t==1) {
    solve1();
  } else {
    solve2();
  }
}
