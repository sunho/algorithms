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

    int n;
    cin >> n;
    vector<pii> A(n);
    rep(i, 0, n) cin >> A[i].x >> A[i].y;
    int m;
    cin >> m;
    vector<pii> B(m);
    rep(i, 0, m) cin >> B[i].x >> B[i].y;

    auto solve = [&](vector<pii>& A, vector<pii>& B) -> int{
        vi l,r;
        trav(x, A) r.push_back(x.y);
        trav(x, B) l.push_back(x.x);

        int ml = *max_element(all(l));
        int mr = *min_element(all(r));
        return max(0, ml-mr);
    };

    cout << max(solve(A,B), solve(B,A)) << "\n";
    
    return 0;
}
