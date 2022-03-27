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

ll mod(ll x,ll N){
    return (x % N + N) %N;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    // odd
    // 1 2 3 4 5 | 2 4 
    // even
    // 1 2 3 4 5 6 | 2 4 6
    // 1 2 3 4 | 2 4 4
    // 1 32
    // 


    ll n,q;
    cin >> n >> q;

    while(q--) {
        ll i;
        cin >> i;
        --i;
        if (i%2 == 0) {
            cout << i/2 + 1 << "\n";
            continue;
        }
        ll j = i;
        ll k = n;
        ll l = 0;
        while (j % 2 != 0) {
            j = n + j/2;
        }
        cout << j/2 + 1 << "\n";
    // i/2 if i%2 == 0
    // (n+1)/2 + (-i/2+(n%2)) mod (n/2)
    }


    return 0;
}
