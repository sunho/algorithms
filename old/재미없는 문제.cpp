#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  cout << 0 << " ";
  int sum = 0;
  bool done = false;
  if (m == 0) done = true;
  for (int i=0;i<n/2;i++){
    if (done) {
      cout << 0 << " ";
      continue;
    }
    cout << 1 << " ";
    sum ++;
    if (sum == m) {
      done = true;
    }
  }
  for (int i=0;i<n-n/2-1;i++){
    if (done) {
      cout << 0 << " ";
      continue;
    }
    if (sum + n/2 >= m) {
      cout << m - sum << " ";
      done = true;
    } else {
      sum += n/2;
      cout << n/2 << " ";
    }
  }
}
