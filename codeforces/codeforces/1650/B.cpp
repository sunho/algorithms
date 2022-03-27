#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int t;
    cin >> t;
    while(t--) {
        int l,r,a;
        cin >> l >> r >> a;
        int maxi = (r/a + r%a);
        int cand = r - r%a - 1;
        if (l <= cand && cand <= r) {
            int mm = cand/a + cand%a;
            ckmax(maxi, mm);
        }
        cout << maxi << '\n';
    }

    return 0;
}