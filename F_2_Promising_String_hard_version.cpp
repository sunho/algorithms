#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(x,a) for(auto& x : (a))
#define nl '\n'
template<class T> using vec = vector<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }
template<class N> N mod(N x, N d) { return ((x%d) + d) % d; }

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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;

    vec<fenwick_tree> ft(3, fenwick_tree(2*n+1, n));
    vec<int> S(n+1);
    rep(i,0,n) {
        S[i+1] = S[i];
        if (s[i] == '-') S[i+1]++;
        else S[i+1]--;
    }

    // S[r+1] = S[l] (mod 3) and (S[r+1] >= S[l])
    rep(i,0,n+1) {
        cnt += ft[mod(S[i],3)].query(-n, S[i] + 1);
        ft[mod(S[i],3)].update(S[i], 1);
    }
    cout << cnt << nl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
