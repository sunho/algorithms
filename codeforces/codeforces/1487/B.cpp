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

template<class Num> Num mod(Num x, Num divisor)
{
    Num m = x % divisor;
    return m + (m < 0 ? divisor : 0);
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        --k;
        if (n % 2 == 0) {
            cout << k % n + 1 << "\n";
            continue;
        }
        if (n == 3) {
            cout << (-(k%n)+n) % n + 1 << "\n";
            continue;
        }
        int i = n / 2;
        int off = max(k, 0);
        cout << (k + off / i)%n +1 << "\n";
    }
    // 3 2 1 3 2 1
    // 1 3 2 1 3 2
    // 1 1 1 1 1 1
    // k = i
    // -off mod n = 2i + 1 mod n
    // off mod n = -(2i + 1) mod n
    // i + off mod n
    // 7 6 5 4 3 2 1 7 6 5 4 3 2 1 7 6 5 4 3 2 1
    // 1 2 3 5 6 7 2 3 4 6 7 1 3 4 5 7 1 2 4 5 6
    //       3     3     3     3     3
    // 5 4 3 2 1 5 4 3 2 1
    // 1 2 4 5 2 3 5 1 3 4
    //     3   2   2   2  

    return 0;
}
