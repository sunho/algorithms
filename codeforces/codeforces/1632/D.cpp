#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

const int N = 1e5;  // limit for array size
int n;  // array size

template<class T>
struct ConstSegTree {
    ConstSegTree() = delete;
    ConstSegTree(int N) : N(N), t(2 * N) {
    }

    T combine(T a, T b){
        if (a==0) return b;
        return __gcd(a,b);
    }

    void build(const vector<T>& arr) {  // build the tree
        n = arr.size();
        for(int i=0;i<n;i++) t[i+n] = arr[i];
        for (int i = n - 1; i > 0; --i) t[i] = combine(t[i*2], t[i*2 + 1]);
    }

    void modify(int p, T value) {  // set value at position p
        for (t[p += n] = value; p > 1; p /= 2) t[p/2] = combine(t[p], t[p^1]);
    }

    T query(int l, int r) {  // sum on interval [l, r)
        T res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) res = combine(res, t[l++]);
            if (r&1) res = combine(res, t[--r]);
        }
        return res;
    }


    int N;
    vector<T> t;
    int n;
};

ConstSegTree<int> ST(2e5+5);

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vi A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    ST.build(A);


    int cnt = 0;
    int of = 0;
    for(int i=0;i<n;i++) {
        if (A[i] == 1) {
            ++cnt;
            of = i+1;
        } else {
            if (of != i) {
                int l = of;
                int r = i + 1;
                while(r - l > 1){
                    int mid = l + (r - l)/2;
                    int dl = i - mid + 1;
                    if (dl >= ST.query(mid,i+1)) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                int dl = i - l + 1;
                if (ST.query(l, i+1) == dl) {
                    ++cnt;
                    of = i+1;
                }
            }
        }
        cout << cnt << ' ';
    }
    cout << '\n';



    return 0;
}