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
    
    int n,m;
    cin >> n >> m;
    vector<pii> A(n);
    vector<pii> B(m);
    rep(i,0,n) cin >> A[i].x;
    rep(i,0,n) cin >> A[i].y;
    rep(i,0,m) cin >> B[i].x;
    rep(i,0,m) cin >> B[i].y;
    vector<pair<pii, int>> C;
    rep(i,0,n) C.push_back({A[i], 0});
    rep(i,0,m) C.push_back({B[i], 1});
    sort(all(C));
    bool ans = true;
    multiset<int> S;
    for(int i = C.size()-1; i >= 0; i--) {
        if (C[i].y == 1) {
            S.insert(C[i].x.y);
        } else {
            pii c = C[i].x;
            auto it = S.lower_bound(c.y);
            if (it == S.end()) {
                ans = false;
                break;
            }
            S.erase(it);
        }
    }
    if (ans) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
