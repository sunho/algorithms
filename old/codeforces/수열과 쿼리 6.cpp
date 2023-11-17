#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

struct mo_query {
  int n;
  vector<pair<int, int>> lr;

  explicit mo_query(int n) : n(n) {}

  void add(int l, int r) { /* [l, r) */
    lr.emplace_back(l, r+1);
  }

  template< typename AL, typename AR, typename EL, typename ER, typename O >
  void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
    int q = (int) lr.size();
    int bs = n / min< int >(n, (int)sqrt(q));
    vector< int > ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
      if(ablock != bblock) return ablock < bblock;
      return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
    });
    int l = 0, r = 0;
    for(auto idx : ord) {
      while(l > lr[idx].first) add_left(--l);
      while(r < lr[idx].second) add_right(r++);
      while(l < lr[idx].first) erase_left(l++);
      while(r > lr[idx].second) erase_right(--r);
      out(idx);
    }
  }

  template< typename A, typename E, typename O >
  void build(const A &add, const E &erase, const O &out) {
    build(add, add, erase, erase, out);
  }
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> A(n);
	for (int i=0;i<n;i++){
		cin >> A[i];
	}
	int q;
	cin >> q;
	mo_query mo(n);
	for (int i=0;i<q;i++){
		int l,r;
		cin >> l >> r;
		--l,--r;
		mo.add(l,r);
	}

	const int N = 100005;
	vector<int> cnt(N);
	vector<int> freq(N);
	vector<int> ans(q);
	int now = 0;
	auto add = [&](int i) {
		cnt[A[i]]++;
		freq[cnt[A[i]]]++;
		if (cnt[A[i]] > now) now = cnt[A[i]];
	};
	auto remove = [&](int i) {
		if (now == cnt[A[i]] && freq[cnt[A[i]]] == 1) now--;
		freq[cnt[A[i]]]--;
		cnt[A[i]]--;
	};
	auto query = [&](int i) {
		ans[i] = now;
	};
	mo.build(add, remove, query);
	for (int i=0;i<q;i++){
		cout << ans[i] << "\n";
	}
}
