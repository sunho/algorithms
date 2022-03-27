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
const int NN = N*N;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> cnt2;
int _cnt[2*NN*N+40];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int* cnt = _cnt + NN*N;
    cnt2.reserve(1 << 16);

    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i,0,n) cin >> A[i];
    
    int nans = 0;
    rep(b,-N,N) {
        rep(i, 0, n) {
            cnt2[A[i] - b * i]++;
            ckmax(nans, cnt2[A[i] - b * i]);
        }
        rep(i, 0, n) {
            cnt2[A[i] - b * i] = 0;
        }
    }

    rep(i,0,n) {
        rep(j, 1, N) {
            if (i+j >= n) continue;
            
            if ((A[i+j] - A[i])%(j) == 0) {
                cnt[(A[i+j] - A[i])/j]++;
                ckmax(nans, cnt[(A[i+j] - A[i])/j] +1);
            }
        }
        rep(j, 1, N) {
            if (i+j >= n) continue;
            cnt[(A[i+j] - A[i])/j]=0;
        }
    }

    cout << n - nans << '\n';
    
    return 0;
}
