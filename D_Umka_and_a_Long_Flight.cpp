#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 45;
vector<ll> fib(N+1);

bool check(int n, int w, int h, int x, int y) {
  if (n == 1) return true;
  if (x < fib[n-2]) {
    return check(n-1, h, fib[n-2], y, x);
  } else if (x >= fib[n-1]) {
    return check(n-1, h, fib[n-2], y, x-fib[n-1]);
  } else {
    return false;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;

  fib[0] = 1;
  fib[1] = 1;
  for (int i=2;i<=N;i++){
    fib[i] = fib[i-1] + fib[i-2];
  }

  while (t--) {
    int n, x, y;
    cin >> n >> y >> x;
    ++n;
    --x,--y;
    if (check(n, fib[n], fib[n-1], x, y)) 
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
}
