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

    int n;
    cin >> n;
    string s;
    cin >> s;

    vi b(n);
    rep(i, 0, n) { 
        if (s[i] == 'r') b[i] = 1;
        else b[i] = 0;
    }

    auto solve = [&](int s) {
        int x = 0, y = 0;
        rep(i,0,n) {
            if (b[i] != s) {
                if (s) x++; else y++;
            }
            s ^= 1;
        }
        return (x+y)-min(x,y);
    };
    cout << min(solve(0),solve(1)) << '\n';

    return 0;
}
