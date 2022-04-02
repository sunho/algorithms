struct fenwick_tree {
    // [-bias, n - bias)
    fenwick_tree(int n, int bias=0) : sums(n), bias(bias) {}
    void update(int pos, ll dif) { // a[pos] += dif
        pos += bias;
        for (; pos < sums.size(); pos |= pos + 1) sums[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        pos += bias;
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += sums[pos-1];
        return res;
    }
    ll query(int l, int r) { // sum of values in [l, r)
        return query(r) - query(l);
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sums.size() && sums[pos + pw-1] < sum)
                pos += pw, sum -= sums[pos-1];
        }
        return pos-bias;
    }
private:
    vector<ll> sums;
    ll bias;
};

struct fenwick_tree_lazy {
    fenwick_tree_lazy(int n) : sums(n) {}
    void add(int idx, int val) {
        for (++idx; idx < sums.size(); idx += idx & -idx)
            sums[idx] += val;
    }
    // add val to [l, r) 
    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
    ll point_query(int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += sums[idx];
        return ret;
    }
private:
    vector<ll> sums;
};