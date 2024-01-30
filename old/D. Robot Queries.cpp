#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  map<char, pair<int,int>> cvt;
  cvt['U'] = {0,1};
  cvt['D'] = {0,-1};
  cvt['L'] = {-1,0};
  cvt['R'] = {1,0};
  auto add = [](pair<int,int> a, pair<int,int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
  };
  vector<pair<int,int>> pf(n+1);
  vector<pair<int,int>> rpf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = add(pf[i], cvt[s[i]]);
  }
  reverse(begin(s),end(s));
  for (int i=0;i<n;i++){
    rpf[i+1] = add(rpf[i], cvt[s[i]]);
  }
  map<pair<int,int>, vector<int>> S, RS;
  for (int i=0;i<=n;i++) {
    S[pf[i]].push_back(i);
    RS[rpf[i]].push_back(i);
  }
  for (int i=0;i<q;i++) {
    pair<int,int> p;
    int l,r;
    cin >> p.first >> p.second >> l >> r;
    --l,--r;
    bool ok = false;
    if (S.count(p)) {
      if (upper_bound(S[p].begin(), S[p].end(), l) != S[p].begin()) {
        ok = true;
      }
      if (*--S[p].end() >= r+1) {
        ok = true;
      }
    }
    int rl = n-1-l, rr = n-1-r;
    swap(rl,rr);
    pair<int,int> q = add(p, {rpf[rl].first-pf[l].first,rpf[rl].second-pf[l].second});
    if (RS.count(q)) {
      auto it = upper_bound(RS[q].begin(), RS[q].end(), rr+1);
      if (it != RS[q].begin() && *--it >= rl+1) {
        ok = true;
      }
    }
    if (ok) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
