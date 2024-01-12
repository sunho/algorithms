#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int mn, int mx) {
  uniform_int_distribution<int> gen(mn, mx);
  return gen(rng);
}

void solve() {
  int n;
  cin >> n;
  map<string,int> M;
  map<int,string> M_inv;
  vector<vector<pair<int,int>>> A(n);
  for (int i=0;i<n;i++){
    int m;
    cin >> m;
    for (int j=0;j<m;j++){
      string s; 
      cin >> s;
      char clause = s[0];
      string name = s.substr(1);
      if (!M.count(name)) {
        M[name] = M.size();
        M_inv[M[name]] = name;
      }
      A[i].push_back({M[name], clause == '+'});
    }
  }
  const int m = M.size();
  vector<vector<vector<int>>> st(m, vector<vector<int>>(2));
  for (int i=0;i<n;i++){
    for (auto [x,c] : A[i]) {
      st[x][c].push_back(i);
    }
  }
  vector<int> S(m);
  const int MAXN = 1000;
  for (int k=0;k<MAXN;k++) {
    for (int i=0;i<m;i++) {
      S[i] = rnd(0,1);
    }
    vector<int> cnt(n);
    const auto check_all = [&]() {
      for (int i=0;i<n;i++) {
        if (3*cnt[i] <= A[i].size())
          return false;
      }
      return true;
    };
    for (int i=0;i<n;i++) {
      for (auto [x,c] : A[i]) {
        if (S[x] == c) {
          cnt[i]++;
        }
      }
    }
    for (int z=0;z<6*m;z++) {
      if (check_all()) {
        for (int i=0;i<m;i++){
          if (S[i]) {
            cout << M_inv[i] << "\n";
          }
        }
        return;
      }
      vector<int> pick;
      for (int i=0;i<n;i++) {
        if (3*cnt[i] <= A[i].size()) {
          pick.push_back(i);
        }
      }
      int cc = pick[rnd(0,pick.size()-1)];
      vector<int> pick2;
      for (int x=0;x<A[cc].size();x++) {
        auto [xx,c] = A[cc][x];
        if (S[xx] != c) {
          pick2.push_back(xx);
        }
      }
      int fc = pick2[rnd(0, pick2.size()-1)];
      for (int x : st[fc][S[fc]]) {
        cnt[x]--;
      }
      for (int x : st[fc][S[fc]^1]) {
        cnt[x]++;
      }
      S[fc]^=1;
    }
  }
  assert(false);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
