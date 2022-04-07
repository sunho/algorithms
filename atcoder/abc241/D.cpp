#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
    int q;
    cin >> q;
    multiset<ll> S;
    while (q--){
        int t;
        cin >> t;
        switch(t) {
        case 1: {
            ll x;
            cin >> x;
            S.insert(x);
            break;
        }
        case 2: {
            ll x, k;
            cin >> x >> k;
            auto it = S.upper_bound(x);
            int i=1;
            if (it == S.begin()) {
                cout << -1 << "\n";
                break;
            }
            --it;
            while (i<k){
                if (it == S.begin()) break;
                --it;
                i++;
            }
            if (i == k && it != S.end()) {
                cout << *it << "\n";
            } else {
                cout << -1 << "\n";
            }
            break;
        }
        case 3: {
            ll x, k;
            cin >> x >> k;
            auto it = S.lower_bound(x);
            int i=1;
            if (it == S.end()) {
                cout << -1 << "\n";
                break;
            }
            while (i<k){
                ++it;
                if (it == S.end()) break;
                i++;
            }
            if (i == k && it != S.end()) {
                cout << *it << "\n";
            } else {
                cout << -1 << "\n";
            }
            break;
        }
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
