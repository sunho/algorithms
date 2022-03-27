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
    while (t--) {
        int n;
        cin >> n;
        string s;
        int i = 0;
        for(int i=0;i<n/3;i++) {
            if (n%3 == 0) {
                cout << "21";
            } else if (n%3 == 1) {
                cout << "12";  
            } else {
                cout << "21";
            }
        }
        if (n%3 !=0) {
            cout << (char)((n%3) + '0');
        }
        cout << '\n';
       

    }

    return 0;
}