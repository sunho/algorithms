#include <bits/stdc++.h>
using namespace std;
using ull = __int128;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ull M = 1049960;
const ull INF = 1e18 + 10;
ull add(ull a, ull b) {
   ull c = a + b ;
   if (c >= INF)
      return INF ;
   return c ;
}
ull mul(ull a, ull b) {
   if (b > 0 && a > INF / b)
      return INF ;
   return a * b ;
}
void solve() {
    unsigned long long N;
    cin >> N;
    ull mini = 1e18 + 10;
    auto calc = [&](ull a, ull m) {
        return a*a*a + a*m*m + m*a*a + m*m*m;
    };
    for(ull a=0;a<=M;a++){
        int l = -1, r = a+1;
        while (r-l > 1) {
            ull m = (l+r) / 2;
            ull f = calc(a,m);
            if (f >= N) r = m;
            else l = m;
        }
        if (calc(a,r) >= N && ckmin(mini,calc(a,r))) {
        }
    }
    cout << (unsigned long long)mini << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}