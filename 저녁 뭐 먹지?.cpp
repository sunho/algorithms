#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct TwoSat {
	int N;
	vector<vector<int>> gr;
	vector<int> values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}

	void setValue(int x) { either(x, x); }
	vector<int> val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		for (int i=0;i<2*N;i++) if (!comp[i]) dfs(i);
		for(int i=0;i<N;i++) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A;
  vector<int> Q;
  for (int i=0;i<n;i++){
    int t;
    cin >> t;
    if (t == 1) {
      int a,b;
      cin >> a >> b;
      A.push_back({a,b});
    } else {
      Q.push_back(A.size());
    }
  }
  int m = A.size();
  const int N = 1e5;
  auto check = [&](int s) {
    TwoSat sat(N);
    for (int i=0;i<s;i++){
      auto [x,y] = A[i];
      if (x < 0) {
        x = ~(-x-1);
      } else {
        x--;
      }
      if (y < 0) {
        y = ~(-y-1);
      } else {
        y--;
      }
      sat.either(x,y);
    }
    return sat.solve();
  };
  int ok = 0, ng=m+1;
  while (ng-ok>1){
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  for (int i=0;i<Q.size();i++){
    int q = Q[i];
    if (q >= ng ) {
      cout << "NO DINNER" << "\n";
    } else {
      cout << "YES DINNER" << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
