#include <bits/stdc++.h>

using namespace std;

std::random_device rd{};
std::mt19937 rng(rd());

set<int> prime_factors(int n) {
  set<int> primes;
  for (int i=2;i*i<=n;i++){
    while (n % i == 0) {
      primes.insert(i);
      n/=i;
    }
  }
  if (n != 1) {
    primes.insert(n);
  }
  return primes;
}

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  sort(begin(A),end(A));
  auto check = [&](int d, int s) {
    int val = A[s] % d;
    int cnt = 0;
    for (int i=0;i<n;i++) {
      if (A[i] % d == val) {
        cnt++;
      }
    }
    return cnt;
  };
  int YOLO = 1000;
  while (YOLO--) {
    int i = rng() % n, j = rng() % n;
    if (i == j) continue;
    auto primes = prime_factors(abs(A[j]-A[i]));
    primes.insert(4);
    for (int p : primes) {
      if (p == 2) continue;
      if (check(p, i) > n/2) {
        cout << p << "\n";
        return 0;
      }
    }
  }
  cout << -1 << "\n";
  return 0;
}
