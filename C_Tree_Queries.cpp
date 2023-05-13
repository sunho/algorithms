#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int query(int u, int v) {
  cout << "? " << u + 1 << " " << v + 1 << endl;
  int d;
  cin >> d;
  return d;
}

void answer(int d) {
  cout << "! " << d << endl;
}

int main() {
  int n;
  cin >> n;

  const int inf = 1e9;
  vector<int> dist(n, inf);
  for (int i=2;i<n;i++){
    dist[i] = query(0, i);
  }
  vector<int> dist2(n, inf);
  for (int i=0;i<n;i++){
    if (i == 0 || i == 1) continue;
    dist2[i] = query(1, i);
  }
  ll mini = inf;
  for (int i=0;i<n;i++){
    mini = min(mini, (ll)dist[i] + dist2[i]);
  }
  vector<int> cand;
  for (int i=0;i<n;i++) {
    if (dist2[i] + dist[i] == 3) 
      cand.push_back(i);
  }
  if (mini == 3 && (cand.size() != 2 || query(cand[0], cand[1]) != 1)) {
    answer(1);
    return 0;
  }
  answer(mini);
}
