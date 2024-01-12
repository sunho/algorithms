// computes Euler's totient function of n in O(sqrt(n)) time.
template<typename T>
T totient(T n) {
  T out = 1, s = sqrt(n);
  for (T i = 2; i <= n; i++) {
    if (i > s) i = n;
    if (n%i == 0) {
      n /= i, out *= i-1;
      while (n%i == 0)
        n /= i, out *= i;
    }
  }
  return out;
}
 
// computes totient(i) for i from 0 to n in O(nlogn) time
vector<int> totientsieve(int n) {
  vector<int> p(n+1);
  iota(p.begin(), p.end(), 0);
  for (int i = 2; i <= n; i++)
    if (p[i] == i) for (int j = i; j <= n; j += i)
      p[j] = p[j]/i*(i-1);
  return p;
}
