#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  vector<vector<bool>> M(n, vector<bool>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      char c;
      cin >> c;
      M[i][j] = c == 'O';
    }
  }
  vector ans(n, vector<ll>(n));
  unordered_map<int, int> in, out;
  vector<vector<pair<int,int>>> to_remove(n+1); 

  int off = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (M[i][j]) {
        in[j]++;
        out[j+2*m+off]++;
        to_remove[min(i+m,n)].push_back({j, j+2*m+off});
      }
    }
    for (auto [x,y] : to_remove[i]) {
      in[x]--;
      out[y]--;
    }
    ll cur = 0;
    for (int j=0;j<n;j++){
      cur += in[j];
      if (out.count(j+off))
        cur -= out[j+off];
      ans[i][j] = cur;
    }
    off += 2;
  }
  
  int q;
  cin >> q;
  while (q--){
    int x,y;
    cin >> x >> y;
    --x,--y;
    cout << ans[x][y] << "\n";
  }
}

