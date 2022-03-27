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

    // m_i 1 2 3 4
    // k_i 1 2 3 4
    // 2 3 4
    // if i exists in board, 1/t + (t-1/t)*(1/t-1) + ... k times
    // p(2) = 0 + 1/3 + 2/3*1/2 = 2/3 = sum_j pi_i (k-i/k) * 1/(k-j)
    // p(3) = 1
    // p(4) = 1
    // k <= 20
    // 8/3

    return 0;
}
