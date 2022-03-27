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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> M(n, vector<char>(n));
        rep(i, 0, n) {
            rep(j, 0, n) {
                cin >> M[i][j];
            }
        }
        vector<pii> cands = {{0,1}, {1,0}, {n-1,n-2}, {n-2,n-1}};
        auto invert = [&](int i, int j) {
            if (M[i][j] == '0') M[i][j] = '1';
            else M[i][j] = '0';
        };
        vector<pii> rans;
        rep(mask, 0, 1 << 4) {
            if (__builtin_popcount(mask) > 2) continue;
            vector<pii> ans;
            rep(i, 0, 4) {
                if (mask & (1 << i)) {
                    invert(cands[i].x, cands[i].y);
                    ans.push_back(cands[i]);
                }
            }
            if (M[0][1] == M[1][0] && M[n-1][n-2] == M[n-2][n-1] && M[0][1] != M[n-2][n-1]) {
                rans = ans;
            }
            rep(i, 0, 4) {
                if (mask & (1 << i)) {
                    invert(cands[i].x, cands[i].y);
                }
            }
        }
        cout << rans.size() << endl;
        trav(x, rans) cout << x.x + 1 << " " << x.y +1 <<"\n";
    }
    

    return 0;
}
