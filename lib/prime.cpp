// sieves + lp
// works when N <= 10^7
// O(n log n) time
const int PN = 1e7;
vector<int> lp(PN+1);
vector<int> pr;
for (int i=2; i <= PN; ++i) {
  if (lp[i] == 0) {
    lp[i] = i;
    pr.push_back(i);
  }
  for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= PN; ++j) {
    lp[i * pr[j]] = pr[j];
  }
}

// factor one number count p
// O(sqrt(n))
vector<ll> factorize(ll n) {
  vector<ll> facts;
  for (ll d = 2; d * d <= n; d++) {
    while (n % d == 0) {
      facts.push_back(d);
      n /= d;
    }
  }
  if (n > 1)
    facts.push_back(n);
  return facts;
}

// factor one number count p^k
// O(sqrt(n))
vector<pair<ll,int>> factorize(ll n) {
  vector<pair<ll,int>> facts;
  for (ll d = 2; d * d <= n; d++) {
    int k=0;
    while (n % d == 0) {
      n /= d;
      k++;
    }
    if (k != 0) {
      facts.push_back({d,k});
    }
  }
  if (n > 1)
    facts.push_back({n,1});
  return facts;
}

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


// version 1
vector<int> d;
vector<vector<int>> factors;
d.assign(N, 1);
factors.resize(N);
for (int i = N-1; i > 1; i--)
  for (int j = i; j < N; j += i)
    d[j] = i;
for (int i = 1; i < N; i++)
  for (int x = i; x != 1; x /= d[x])
    factors[i].push_back(d[x]);

for(auto p : factors[r1]) f[p]--;



