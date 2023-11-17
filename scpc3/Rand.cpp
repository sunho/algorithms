#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long a, long long b){
    return a + rng() % (b - a + 1);
}

int main() {
  int n = 10;
  vector<int> A(n);
  A[0] = 1;
  A.back() = 1;
  for (int i=1;i<n-1;i++) {
    A[i] = random(1,2);
  }
  int M = random(1,n), t = random(1,n);
  cout << 1 << "\n";
  cout << n << "\n";
  for (int a : A) cout << a << " ";
  cout << "\n";
  cout << M << " " << t << "\n";
}
