// big prime library
// as the last resort
// it's a dark magic
mt19937 randint((mt19937::result_type)chrono::steady_clock::now().time_since_epoch().count());
 
// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
  return uniform_int_distribution<int>(a, b)(randint);
}
 
// returns a random double from 0 to 1
inline double rand01() {
  return uniform_randint(0, INT_MAX)/double(INT_MAX);
}
 
// randomly and uniformly select k distinct integers in the range [0..n-1]
// runs in O(klog(n/k))
vector<int> random_sample(int k, int n) {
  vector<int> r(k);
  std::iota(r.begin(), r.end(), 0);
  double w = exp(log(rand01())/k);
  int i = k-1;
  while (i < n) {
    i += 1+(int)floor(log(rand01())/log(1-w));
    if (i < n) {
      r[uniform_randint(0, k-1)] = i;
      w *= exp(log(rand01())/k);
    }
  }
  return r;
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
 
// checks if a number is prime in O(log^3(n)) time, randint comes from random.cpp.
// works for n <= 10^18
bool isprime(ll n) {
  static vector<bool> sieve = primesieve(1000000);
  if (n < (int)sieve.size()) return sieve[n];
  if (n%2 == 0) return false;
  ll d = n-1, r = 0;
  while (d%2 == 0) r++, d >>= 1;
  for (int k = 0; k < 30; k++) {
    __int128 x = 1, a = uniform_int_distribution<ll>(2, n-2)(randint);
    for (ll i = 1; i <= d; i <<= 1) {
      if (d&i) x = (x*a)%n;
      a = (a*a)%n;
    }
    bool f = 0;
    if (x == 1 || x == n-1) f = 1;
    for (int i = 1; i < r; i++)
      f = f || (x = (x*x)%n) == n-1;
    if (!f) return false;
  }
  return true;
}

// returns a sorted list of all prime factors of n in O(min(n^(1/2), n^(1/4)+log^3(n)+10^5)) time.
// works for n <= 10^18
vector<ll> primefactors(ll n) {
  static vector<ll> small = primesupto(1000000);
  if (isprime(n)) return {n};
  vector<ll> out;
  for (ll p : small) {
    if (p*p > n || n == 1) break;
    while (n%p == 0)
      n /= p, out.push_back(p);
  }
  if (n == 1 || isprime(n)) {
    if (n != 1) out.push_back(n);
    return out;
  }
  __int128 x = 2, y = 2;
  __int128 c = uniform_int_distribution<ll>(1, n-1)(randint);
  ll f = 0;
  for (ll z = 1; 1; z <<= 1) {
    y = x;
    for (ll i = 0; i < z; i++) {
      x = (((x*x)%n)+c)%n;
      f = gcd((ll)(x-y), n);
      if (f > 1) {
        out.push_back(min(f, n/f)), out.push_back(max(f, n/f));
        return out;
      }
    }
  }
  return out;
}
 
// if n is a prime power, returns that prime, otherwise returns 0, runs in O(log^3(n)) time.
// works for n <= 10^18
ll primepower(ll n) {
  for (ll k = 1; k < 63; k++) {
    __int128 p = 1;
    for (ll i = 1ll<<62; i > 0; i /= 2) {
      __int128 x = 1;
      bool f = 0;
      for (int j = 0; j < k; j++)
        if ((f = f || (x *= (p+i)) > n)) break;
      if (!f && x <= n) {
        p += i;
        if (x == n && isprime((ll)p)) return (ll)p;
      }
    }
  }
  return 0;
}
 
// returns a sorted list of all divisors of n in approximately O(min(n^(1/2), n^(1/3)+log^3(n)+10^5)) time.
// works for n <= 10^18
vector<ll> divisors(ll n) {
  map<ll, int> p;
  for (ll x : primefactors(n))
    p[x]++;
  vector<ll> out = {1};
  for (auto& [q, f] : p) {
    vector<ll> tmp;
    for (ll x : out) {
      ll r = 1;
      for (int i = 0; i <= f; i++) {
        tmp.push_back(x*r);
        r *= q;
      }
    }
    out = tmp;
  }
  return out;
}
