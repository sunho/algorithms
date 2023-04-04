#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MN = 300;
const int MR = 300;

void solve() {
  int n,r,q;
  cin >> n >> r >> q;
  vector<int> R(r);
  array<array<int, MR>, MN> needs{};
  vector<pair<int,int>> logs(q);
  for (int i=0;i<r;i++){
    cin >> R[i];
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<r;j++){
      cin >> needs[i][j];
    }
  }
  for (int i=0;i<q;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    logs[i] = {a,b};
  }
  auto f = [&](int t) -> bool {
    array<array<int, MR>, MN> rel{};
    vector<int> cur = R;
    set<int> worklist;
    for (int i=0;i<t;i++){
      cur[logs[i].second]--;
      rel[logs[i].first][logs[i].second]++;
    }
    for(int i=0;i<n;i++) worklist.insert(i);
    while (!worklist.empty()) {
      int next = -1;
      for (int i : worklist){
        bool ok = true;
        for (int j=0;j<r;j++){
          if (rel[i][j] != needs[i][j] && cur[j] + rel[i][j] < needs[i][j]) {
            ok = false;
            break;
          }
        }
        if (ok){
          next = i;
          break;
        }
      }
      if (next == -1)
        return true;
      worklist.erase(next);
      for (int j=0;j<r;j++){
        cur[j] += rel[next][j];
        rel[next][j]=0;
      }
    }
    return false;
  };

  int ng=-1,ok=q+1;
  while(ok-ng>1){
    int mid = (ng+ok)/2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  if (ok == q + 1) {
    cout << -1 << "\n";
  } else {
    cout << ok << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
