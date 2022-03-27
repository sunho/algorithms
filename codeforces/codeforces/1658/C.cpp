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
template<class N> N mod(N x, N d) { return ((x%d) + d) % d; }

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;

    while (t--) {
        int n;
        int p = -1;
        bool ans = true;
        cin >> n;
        vi A(n);
        rep(i,0,n) {
            cin >> A[i];
            if (A[i] == 1) p = i;
        }
        if (p == -1) {
            ans = false;
        } else {
            rep(i,0,n-1) {
                int j = (p + i + 1) % n;
                int jp = (p + i) % n;
                if (A[j] > A[jp] + 1 || A[j] < 2) ans = false;
            }
        }
        if (ans) cout << "YES" << endl; 
        else cout << "NO" << endl;
    }

    return 0;
}
