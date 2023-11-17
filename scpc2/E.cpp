#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <numeric>

using namespace std;
using ll = long long;
using lll = long long;

// https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
struct Line {
	mutable lll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(lll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const lll inf = numeric_limits<lll>::max();
	lll div(lll a, lll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(lll k, lll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	lll query(lll x) {
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

void print(__int128 x) {
  if (x < 0) {
    cout<<'-';
    x = -x;
  }
  if (x > 9) print(x / 10);
  cout<<(int)(x % 10);
}

void solve() {
	int n,m;
	cin >> n; 
	vector<ll> R(n), D(n);
	for (int i=0;i<n;i++) {
		cin >> R[i];
		cin >> D[i];
	}
	cin >> m;
	vector<ll> P(m), W(m);
	for (int i=0;i<m;i++)
		cin >> P[i];
	for (int i=0;i<m;i++)
		cin >> W[i];

	LineContainer LC;
	for (int i=1;i<m;i++) {
		LC.add(-P[i], -W[i]);
	}

	lll ans = 0;
	for (int i=0;i<n;i++){
		ans += (lll)(D[i]-R[i])*P[0];
	}
	for (int i=0;i<n-1;i++){
		ll dur = R[i+1]-D[i];
		lll mn = (lll)dur * P[0];
		if (m != 1) 
			mn = min(mn, -LC.query(dur));
		ans += mn;
	}
	print(ans);
	cout << "\n";
}

int main() {
	
	int T;
	cin >> T;
	for(int t=0;t<T;t++) {
		cout << "Case #" << t+1 << "\n";
		solve();
	}

	return 0;
}
