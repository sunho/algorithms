template<class T>
struct ConstSegTree {
    ConstSegTree() = delete;
    ConstSegTree(int N) : N(N), t(2 * N) {
    }
 
    T combine(T a, T b) {
        return __gcd(a,b);
    }
 
    void build(const vector<T>& arr) {  // build the tree
        n = arr.size();
        for (int i=0;i<n;i++) t[i+n] = arr[i];
        for (int i = n - 1; i > 0; --i) t[i] = combine(t[i*2], t[i*2+1]);
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