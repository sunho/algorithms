#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> treeJump(vector<int>& P){
	int d = ceil(log2(P.size()));
	vector<vector<int>> up(d, P);
	for(int i=1;i<d;i++) for(int j=0;j<P.size();j++)
		up[i][j] = up[i-1][up[i-1][j]];
	return up;
}

int jmp(vector<vector<int>>& up, int node, int steps){
	for(int i=0;i<up.size();i++)
		if(steps&(1<<i)) node = up[i][node];
	return node;
}

ll jmpSum(vector<vector<int>>& up, vector<vector<ll>>& sum, int node, int steps){
  ll res = 0;
	for (int i = up.size()-1;i>=0;i--){
		if(steps&(1<<i)) {
      res += sum[i][node];
      node = up[i][node];
    }
  }
	return res;
}

vector<vector<ll>> sumJump(vector<vector<int>>& up, vector<ll>& A){
	int d = ceil(log2(A.size()));
	vector<vector<ll>> res(d, vector<ll>(A.size()));
  res[0] = A;
	for(int i=1;i<d;i++) for(int j=0;j<A.size();j++)
		res[i][j] = res[i-1][j] + res[i-1][up[i-1][j]];
	return res;
}

void solve() {
  int n,k,d,q;
  cin >> n >> k >> d >> q;
  vector<vector<pair<int,int>>> D(k);
  vector<pair<int,int>> C(n);
  for (int i=0;i<n;i++){
    cin >> C[i].first;
  }
  for (int i=0;i<n;i++){
    cin >> C[i].second;
  }
  for (int i=0;i<n;i++){
    D[C[i].second].push_back({C[i].first, i});
  }
  for (int i=0;i<k;i++){
    sort(begin(D[i]),end(D[i]));
  }
  vector<int> P(n);
  vector<ll> A(n);
  for (int i=0;i<n;i++){
    int cur = C[i].first;
    int a = C[i].second;
    int j = (int)(lower_bound(begin(D[(a+1)%k]), end(D[(a+1)%k]), make_pair(cur,0))-begin(D[(a+1)%k]));
    int dist = 0;
    auto [nxt_pos, nxt_i] = D[(a+1)%k][j % (int)D[(a+1)%k].size()];
    if (j == (int)D[(a+1)%k].size()) {
      j = 0;
      dist = d - cur + nxt_pos;
    } else {
      dist = nxt_pos - cur;
    }
    P[i] = nxt_i;
    A[i] = dist;
  }
  auto jump = treeJump(P);
  auto sum = sumJump(jump, A);
  while (q--){
    int x,y,z;
    cin >> x >> y >> z;
    if (z == 0) {
      cout << 0 << "\n";
      continue;
    }
    int j = (int)(lower_bound(begin(D[y]), end(D[y]), make_pair(x,0))-begin(D[y]));
    ll dist = 0;
    auto [nxt_pos, nxt_i] = D[y][j % D[y].size()];
    if (j == (int)D[y].size()) {
      j = 0;
      dist = d - x + nxt_pos;
    } else {
      dist = nxt_pos - x;
    }
    z--;
    dist += jmpSum(jump, sum, nxt_i, z);
    cout << dist << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
