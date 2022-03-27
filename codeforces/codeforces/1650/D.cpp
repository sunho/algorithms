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
        vi A(n);
        vi B(n);
        vi ans(n);
        for(int i=0;i<n;i++) cin >> A[i];
        bool okay = true;
        for(int i=n;i>=2;i--) {
            bool found = false;
            int x;
            for(int j=0;j<i;j++) {
                if (A[j] == i) {
                    x = j;
                    found = true;
                    break;
                }
            }
            if (!found) {
                okay = false;
                break;
            }
            int delta = x == i-1 ? 0 : ((x + 1) % i);
            B = A;
            for(int j=0;j<i;j++) {
                B[j] = A[(j + delta)%i];
            }
            A=B;
            ans[i-1] = delta;
        }
        if (!okay) { 
            cout << -1 << '\n';
        } else {
            for(int i=0;i<n;i++) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }

    }

    return 0;
}