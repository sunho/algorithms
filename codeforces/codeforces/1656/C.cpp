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
        vi A(n);
        set<int> S;
        rep(i, 0, n) {
            cin >> A[i];
            S.insert(A[i]);
        }
        if (!S.count(1)) {
            cout << "YES" << "\n";
            continue;
        }
        if (S.size() == 1 && S.count(1)) {
            cout << "YES" << "\n";
            continue;
        }
        if (S.count(1) && S.count(2)) {
            cout << "NO" << "\n";
            continue;
        }
        if (S.count(1) && S.count(0)) {
            cout << "NO" << "\n";
            continue;
        }
        bool ans = true;
        while(!S.empty()) {
            auto it = --S.end();
            if (*it <= 2) {
                break;
            }
            if (*it - 1 >= 2 && S.count(*it-1)) {
                ans = false;
                break;
            }
            S.erase(it);
        }
        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
