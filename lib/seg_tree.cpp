template<class T>
struct seg_tree {
    // [-bias, n - bias)
    seg_tree(int n, int bias=0) : n(n), bias(bias), seg(2*n) {}
    seg_tree(const vector<T>& arr, int bias=0) : n(arr.size()), bias(bias), seg(2 * n) {
        for (int i=0;i<n;i++) seg[i+n] = arr[i];
        for (int i = n - 1; i > 0; --i) seg[i] = combine(seg[i*2], seg[i*2+1]);
    }
    T combine(T a, T b) { return a+b; }
    void set(int p, T value) { // set value at position p
        p+=bias,p+=n;
        seg[p] = value;
        for (; p > 1; p /= 2) seg[p/2] = combine(seg[p], seg[p^1]);
    }
    void update(int p, T value) { // set value at position p
        p+=bias,p+=n;
        seg[p]+=value;
        for (; p > 1; p /= 2) seg[p/2] = combine(seg[p], seg[p^1]);
    }
    T query(int l, int r) { // on interval [l, r)
        T res = 0;
        l+=bias,r+=bias;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) res = combine(res, seg[l++]);
            if (r&1) res = combine(res, seg[--r]);
        }
        return res;
    }
 private:
    int n;
    int bias;
    vector<T> seg;
};

struct lazy_seg_tree {
    lazy_seg_tree() = delete;
    lazy_seg_tree(int n) : n(n), d(n), t(2*n), h(sizeof(int) * 8 - __builtin_clz(n)) {
    }
    int combine(int a, int b) {
        return max(a,b);
    }
    void apply(int p, int value) {
        t[p] += value;
        if (p < n) d[p] += value;
    }
    void build(int p) {
        while (p > 1) p >>= 1, t[p] = combine(t[p<<1], t[p<<1|1]) + d[p];
    }
    void push(int p) {
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            if (d[i] != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = 0;
            }
        }
    }
    void inc(int l, int r, int value) {
        l += n, r += n;
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) apply(l++, value);
            if (r&1) apply(--r, value);
        }
        build(l0);
        build(r0 - 1);
    }
    int query(int l, int r) {
        int res = -2e9;
        l += n, r += n;
        push(l);
        push(r - 1);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = combine(res, t[l++]);
            if (r&1) res = combine(t[--r], res);
        }
        return res;
    }
    int n;
    vector<int> d;
    vector<int> t;
    int h;
};