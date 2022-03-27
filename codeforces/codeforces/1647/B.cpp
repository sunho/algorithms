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
        int n,m;
        cin >> n >> m;
        vector<vector<int>> M(n, vi(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                char b;
                cin >> b;
                M[i][j] = b-'0';
            }
        }
        bool okay = true;
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<m-1;j++) {
                int cnt = 0;
                cnt += M[i][j];
                cnt += M[i+1][j];
                cnt += M[i][j+1];
                cnt += M[i+1][j+1];
                if (cnt == 3) {
                    okay = false;
                }
            }
        }
        if (!okay) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}