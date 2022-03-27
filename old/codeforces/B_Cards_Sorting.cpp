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

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
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
			if (pos + pw <= s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

const int N = 100000 + 5;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vi A(n);
    vector<vector<int>> S(N);
    set<int> nums;
    FT ft(n);
    rep(i,0,n) {
        cin >> A[i];
        S[A[i]].push_back(i);
        nums.insert(A[i]);
    }
    vi B;
    int last = 0;
    trav(x, nums) {
        auto& V = S[x];
        auto k = lower_bound(all(V), last) - V.begin();
        rep(i,0,V.size()) {
            B.push_back(V[(i+k)%V.size()]);
        }
        last = V[(k-1+V.size())%V.size()];
    }
    ll cnt = 0;
    int l = 0;
    rep(i, 0, n) {
        if (l > B[i]) {
            // [l, n)
            int rem = ft.query(n) - ft.query(l);
            cnt += n - l - rem;
            l = 0;
        }
        // [l, B[i])
        int rem = ft.query(B[i]) - ft.query(l);
        cnt += B[i] - l - rem + 1;
        ft.update(B[i], 1);
        l = (B[i] + 1) % n;
    }
    cout << cnt << '\n';
    
    return 0;
}
