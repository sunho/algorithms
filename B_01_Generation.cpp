#include <bits/stdc++.h>
#include <cmath>
#include <deque>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  deque<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  int cur = 0;
  while (!A.empty()) {
    int c = (A.back() ^ cur);
    if (c == 0) { 
      A.pop_back();
    } else {
      if ((A[0] ^ cur) != 0) {
        cout << "No" << "\n";
        return 0;
      }
      cur ^= 1;
      A.pop_front();
    }
  }
  cout << "Yes" << "\n";
}
