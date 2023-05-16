#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10000;

int rrotate_digits(int x) {
  int res = (x % 10) * 1000 + (x/10);
  return res;
}

int lrotate_digits(int x) {
  int res = ((x / 1000) + (x*10)) % N;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int u, v;
    cin >> u >> v;
    // assert(dist[u][v] != -1);
    string ans;
    vector<int> dist(N, -1);
    vector<int> prd(N, -1);
    vector<char> prd_choice(N, ' ');
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      pair<int, char> cands[] = {
        {lrotate_digits(u), 'L'},
        {rrotate_digits(u), 'R'},
        {(2*u) % N, 'D'},
        {(u-1+N)%N, 'S'}
      };
      for (auto [v, c] : cands){
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          prd[v] = u;
          prd_choice[v] = c;
          q.push(v);
        }
      } 
    }
    for (int cur = v; cur != u; cur = prd[cur]) {
      ans.push_back(prd_choice[cur]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
  }
}
