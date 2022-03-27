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

const int N = 320; // sqrt(10^5)

int maxfreq(vector<ll>& a) {
    int res = 0;
    int cur = 0;
    sort(all(a));
    rep(i, 0, a.size()) {
        if (i == 0 || a[i] == a[i-1]) {
            cur++;
            ckmax(res, cur);
        } else {
            cur = 1;
        }
    }
    return res;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);


    // a_i = b*i + c
    // a_i <= 10^5
    // a_j - a_i = b*(j-i)
    // b*(j-i) <= 10^5
    // b > sqrt(10^5) -> (j-i) < sqrt(10^5)
    // every b sqrt(10^5) * 10^5
    // delta <= sqrt(10^5) sqrt(10^5) * 10^5
    //
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i,0,n) cin >> A[i];
    
    int nans = 0;
    rep(b,-N,N) {
        vector<ll> f;
        rep(i, 0, n) {
            f.push_back(A[i] - b * i);
        }
        ckmax(nans, maxfreq(f));
    }

    rep(i,0,n) {
        vector<ll> f;
        rep(j, 1, N) {
            if (i+j >= n) continue;
            if ((A[i+j] - A[i])%(j) == 0) {
                f.push_back((A[i+j] - A[i])/j);
            }
        }
        ckmax(nans, maxfreq(f) +1);
    }

    cout << n - nans << '\n';
    
    return 0;
}
