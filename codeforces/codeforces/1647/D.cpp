#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--) {
        int x, d;
        cin >> x >> d;
        if (x % d != 0) {
            cout << "NO" << '\n';
            continue;
        }
        int x2 = x;
        int logx = 0;
        while (x2 % d == 0) {
            x2/=d;
            logx++;
        }
        if (logx <= 1) {
            cout << "NO" << '\n';
            continue;
        }
        int q = x;
        for(int i=0;i<logx;i++) {
            q /= d;
        }
        if (!isPrime(q) && q != 1) {
            cout << "YES" << '\n';
            continue;
        }

        if (isPrime(d)) {
            cout << "NO" << "\n";
            continue;
        }


        if (logx >= 4) {
            cout << "YES" << '\n';
        } else {
            if (q==1 && logx >= 3) {
                cout << "YES" << '\n';
            } else if (logx >= 3 && q*q != d) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            
        }
    }

    return 0;
}