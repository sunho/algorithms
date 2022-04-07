#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    i64 cnt = 0;

    vec<FT> ft(3, FT(2*n+1));
    vec<int> S(n+1);
    rep(i,0,n) {
        S[i+1] = S[i];
        if (s[i] == '-') S[i+1]++;
        else S[i+1]--;
    }

    // S[r+1] = S[l] (mod 3) and (S[r+1] >= S[l])
    rep(i,0,n+1) {
        cnt += ft[mod(S[i],3)].query(0, S[i] + 1 + n);
        ft[mod(S[i],3)].update(S[i]+n, 1);
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
