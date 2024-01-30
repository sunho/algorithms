#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int,ll> A;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    A[i]=a;
  }
  while (A.size() != 1) {
    for (auto it = A.begin(); it != A.end(); it++) {
      ll nw = it->second;
      if (it != A.begin()) {
        if (prev(it)->second <= it->second) {
          nw += prev(it)->second;
          A.erase(prev(it));
        }
      }
      if (next(it) != A.end()) {
        if (next(it)->second <= it->second){
          nw += next(it)->second;
          A.erase(next(it));
        }
      }
      it->second = nw;
    }
  }
  cout << A.begin()->second << "\n" << A.begin()->first + 1<< "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
