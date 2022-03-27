#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define x first
#define y second
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(x,a) for(auto& x : (a))
#define endl '\n'
template<class T> bool ckmin(T&a, const T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T&b) { bool B = a < b; a = max(a,b); return B; }
template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        auto check = [&](ll n, ll k) {
            return n >= k*(k+1)/2 && (n - k*(k+1)/2)%k == 0;
        };
        if (n < 100) {
            ll fk = -1;
            rep(k, 2, n + 1) {
                if (check(n,k)) {
                    fk = k;
                    break;
                }
            };
            cout << fk << "\n";
        } else {
            if (n % 2 == 1) {
                cout << 2 << "\n";
            } else {
                ll p = 1;
                ll q = n;
                while (q%2 == 0) {
                    q /= 2;
                    p*=2;
                }
                if (q == 1) {
                    cout << -1 << "\n";
                } else {
                    if (check(n, 2*p)) {
                        cout << 2*p << "\n";
                    } else {
                        cout << q << "\n";
                    }
                } 
            }
        }
    }   

    return 0;
}
