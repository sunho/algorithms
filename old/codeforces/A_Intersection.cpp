#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int l1,r1,l2,r2;
  cin >> l1 >> r1 >> l2 >> r2;
  pair<int,int> newi = {max(l1,l2), min(r1,r2)};
  if (newi.first <= newi.second) {
    cout << newi.second - newi.first << "\n";
  } else {
    cout << 0 << "\n";
  }
} 

