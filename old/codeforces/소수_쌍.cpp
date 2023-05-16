#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Find lowest prime divisors and prime list in [1,PN]
void sieves(int PN, vector<ll>& lp, vector<ll>& pr) {
  lp.assign(PN+1,0);
  for (int i=2;i<=PN;i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0;j<pr.size()&&pr[j]<=lp[i]&&i*pr[j]<=PN;j++) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];

  const int PN = 2000;
  vector<ll> lp, pr;
  sieves(PN, lp, pr);
  set<int> primes;
  for (ll p : pr) primes.insert(p);
  
  vector adj(n, vector<int>());
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (i == j) continue;
      if (primes.count(A[i] + A[j])) {
        adj[i].push_back(j);
      }
    }
  }

  vector<int> ans;

  for (int p : adj[0]){
    vector<int> mt(n, -1);
    vector<bool> used(n);
    used[0] = true;
    used[p] = true;
    mt[0] = p;
    mt[p] = 0;
    for (int i=1;i<n;i++){
      for (int j : adj[i]) {
        if (used[i] || used[j]) continue;
        mt[i] = j;
        mt[j] = i;
        used[i] = true;
        used[j] = true;
        break;
      }
    }
    vector<bool> vis;
    auto dfs = [&](auto self, int u) {
      if (vis[u]) return false;
      vis[u] = true;
      for (int v : adj[u]) {
        if (v == 0 || mt[v] == 0) continue;
        if (mt[v] == -1 || self(self, mt[v])) {
          mt[u] = v;
          mt[v] = u;
          return true;
        }
      }
      return false;
    };
    for (int i=1;i<n;i++){
      if (used[i]) continue;
      vis.assign(n,false);
      dfs(dfs,i);
    }
    bool ok = true;
    for (int i=0;i<n;i++){
      if (mt[i] == -1) ok = false;
    }
    if (ok) {
      ans.push_back(A[p]);
    }
  }
  sort(ans.begin(), ans.end());
  if (!ans.size()) {
    cout << -1 << "\n";
  } else {
    for (int p : ans) cout << p << " ";
  }

}
