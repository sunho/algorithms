
struct FT {
	vector<i64> s;
	FT(int n) : s(n) {}
	void update(int pos, i64 dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
	}
	i64 query(int pos) { // sum of values in [0, pos)
		i64 res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
    i64 query(int l, int r) { // sum of values in [l, r)
        return query(r) - query(l);
    }
	int lower_bound(i64 sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};