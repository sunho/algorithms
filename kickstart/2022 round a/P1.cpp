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

    int T;
    cin >> T;
    rep(t, 1, T+1) {
        string I,P;
        cin >> I >> P;
        int l = 0;
        int cnt = 0;
        bool okay = true;
        if (I.size() > P.size()) {
            okay = false;
        } else {
            rep(i, 0, I.size()) {
                while (l < P.size() && P[l] != I[i]) {
                    ++l;
                    ++cnt;
                }
                if (l == P.size()) {
                    okay = false;
                    break;
                }
                ++l;
            }
            if (P.size() != l) {
                cnt += P.size() - l;
            }
        }
        cout << "Case #" << t << ": ";
        if (okay) {
            cout << cnt << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
