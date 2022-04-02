#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long long;
using pii = pair<int, int>;
#define x first
#define y second
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define trav(x,a) for(auto& x : (a))
#define all(x) begin(x), end(x)
#define nl '\n'
template<class T> using vec = vector<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }
template<class N> N mod(N x, N d) { return ((x%d) + d) % d; }

// a_1 * a_2 * a_3 * ... * a_n = N (mod M)
// a1*a2 - N = 0 (mod M)
// M | a1*a2 - N
//
//
    
// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
ul get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}
// Returns a random integer from the range [l, r].
ul randint(ul l, ul r) {
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ul>(l, r)(gen);
}
// Computes (a*b) % mod avoiding integer overflow.
// Assumption: mod < 2**61.
ul BigModMultiplication(ul a, ul b, ul mod) {
    return ((__uint128_t)a * b) % mod;
    
    // The foulowing code should be used only if __uint128 is not available.
    a %= mod, b %= mod;
    ul res = 0;
    while (a > 0) {
        if (a & 1) res += b;
        a >>= 1;
        b <<= 1;
        b %= mod;
        res %= mod;
    }
    return res;
}
// Computes (x**e) % mod avoiding integer overflow.
// Assumption: mod < 2**61.
ul BigModPower(ul x, ul e, ul mod) {
    ul res = 1;
    while (e) {
        if (e & 1) res = BigModMultiplication(res, x, mod);
        e >>= 1;
        x = BigModMultiplication(x, x, mod);
    }
    return res;
}
// Primality test, returns true iff p is prime.
// It implements Miuler-Rabin algorithm (with some optimizations).
// Assumptions:  0 <= p <= 2**61.
// In order to support p > 1e9 it uses BigModMultiplication and BigModPower.
bool IsPrime(ul p) {
    if (p <= 1) return false;
    static const ul first_primes[21] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
                                            29, 31, 37, 41, 43, 47, 53, 59,
                                            61, 67, 71, 73};
    // Checking the divisibility by the first 21 primes.
    for (int i = 0; i < 21; i++) {
        if (p % first_primes[i]== 0) {
            if (p == first_primes[i]) return true;
            return false;
        }
    }
    
    ul x = p-1;
    int e = 0;
    while (x % 2 == 0) {
        x >>= 1;
        e++;
    }
    
    static const map<ul, int> primes_to_check_table = {
        {2047, 1}, {1373653, 2}, {25326001, 3}, {3215031751ULL, 4},
        {2152302898747ULL, 5}, {3474749660383ULL, 6}, {341550071728321ULL, 7},
        {3825123056546413051ULL, 9}, {1ULL<<62, 21}};
    int primes_to_check_num = primes_to_check_table.upper_bound(p)->second;
    
    for (int i = 0; i < primes_to_check_num; i++) {
        bool composite = true;
        ul temp = BigModPower(first_primes[i], x, p);
        if (temp != 1 and temp != p-1) {
            for (int k = 0; k < e; k++) {
                temp = BigModMultiplication(temp, temp, p);
                if (temp == p-1) {
                    composite = false;
                    break;
                }
            }
        }
        else composite = false;
        if (composite) return false;
    }
    return true;
}
// Implementation of Poulard-Rho algorithm to find a nontrivial factor
// of n. As cycle-detection method, Brent's algorithm is used.
// The expected running time is O(sqrt(p)*log(n)) where p is the smaulest prime
// factor of n.
// Assumption: n > 1 is not a prime.
ul FindFactor(ul n) {
    static mt19937_64 gen;
    while (1) {
        ul x = uniform_int_distribution<ul>(1, n-1)(gen);
        ul y = x;
        auto next_x = [&x, n]() { x = (BigModMultiplication(x, x, n)+1) % n; };
        ul res = 1;
        for (int sz = 2; res == 1; sz<<=1) {
            for (int i = 0; i < sz && res == 1; i++) {
                next_x();
                res = __gcd(n+x-y, n);
                if (res != 1 and res != n) {
                    return res;
                }
            }
            y = x;
        }
    }
}
// Returns the factorization of n.
// The returned vector contains pairs (p, e) so that:
//  - The values of p are strictly increasing.
//  - The values of p are primes.
//  - It holds e > 0.
//  - Product of p**e = n.
//
// Assumptions: 1 <= n < 2**61.
vector<pair<ul,int>> factorization(ul n) {
    if (n == 1) return {};
    if (IsPrime(n)) return {{n, 1}};
    ul x = FindFactor(n);
    vector<pair<ul,int>> a = factorization(x);
    vector<pair<ul,int>> b = factorization(n/x);
    
    // Merging a and b.
    sort(all(a));
    sort(all(b));
    vector<pair<ul,int>> res;
    auto add = [&](pair<ul,int> p) {
        if (!res.empty() and res.back().first == p.first)
            res.back().second += p.second;
        else res.push_back(p);
    };
    int ita = 0, itb = 0;
    while (ita < a.size() and itb < b.size()) {
        if (a[ita] < b[itb]) add(a[ita++]);
        else add(b[itb++]);
    }
    while (ita < a.size()) add(a[ita++]);
    while (itb < b.size()) add(b[itb++]);
    return res;
}

void solve() {
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    return 0;
}
