// returns a vector of length n, containing 1 if a number is prime, else 0.
// runs in O(nloglogn) time.
vector<bool> primesieve(int n) {
  vector<bool> sieve(n, 1);
  for (int i = 2; i < n; i++)
    if (sieve[i])
      for (int j = 2*i; j < n; j += i)
        sieve[j] = 0;
  sieve[1] = 0;
  return sieve;
}
 
// returns a sorted list of all primes less than or equal to n.
// runs in O(nloglogn) time.
vector<ll> primesupto(int n) {
  vector<bool> sieve = primesieve(n+1);
  vector<ll> out;
  for (int i = 2; i <= n; i++)
    if (sieve[i]) out.push_back(i);
  return out;
}


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
 
// computes mobius(i) for i from 0 to n in O(nlogn) time
vector<int> mobiussieve(int n) {
  vector<int> m(n+1, -1), p(n+1, 1);
  m[0] = 0, m[1] = 1;
  for (int i = 2; i <= n; i++)
    if (p[i]) for (int j = 2; j*i <= n; j++) {
      if (j%i) m[i*j] = m[i]*m[j];
      else m[i*j] = 0;
      p[i*j] = 0;
    }
  return m;
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
