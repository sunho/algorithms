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
        vector<pair<pii,pii>> ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                // if (i < n-1 && j < m-1 && M[i][j] == 0 && M[i][j+1] == 1 && M[i+1][j] == 1 && M[i+1][j+1] == 0) {
                    
                //     M[i][j+1] = 0;
                //     M[i+1][j+1] = 0;
                // } 
                if (j < m-1 && M[i][j] == 0 && M[i][j+1] == 1) {
                    ans.push_back({{i,j}, {i,j+1}});
                    M[i][j+1] = 0;
                }
                if (i < n-1 && M[i][j] == 0 && M[i+1][j] == 1) {
                    ans.push_back({{i,j}, {i+1,j}});
                    M[i+1][j] = 0;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        

        bool okay = true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (M[i][j] == 1) okay = false;
            
            }
        }
        if(!okay) {
            cout << "-1" << '\n';
        } else {
            cout << ans.size() << '\n';
            for (auto& x:ans) {
                cout << x.first.first + 1 << " " << x.first.second +1 << " " << x.second.first+1 << " " << x.second.second+1 << "\n";
            }
        }
    }

    return 0;
}