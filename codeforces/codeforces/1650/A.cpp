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
        string s;
        char c;
        cin >> s >> c;
        bool okay = false;
        for(int i=0;i<s.size();i++) {
            if (s[i] == c && i % 2 == 0) {
                okay = true;
            }
        }
        if(okay) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }


    return 0;
}