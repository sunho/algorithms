#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    auto dfs = [&](auto dfs, int al, int ar, int bl, int br) -> bool {
      if (bl == br){
        return true;
      }
      if (al == ar){
        return false;
      }
      int mx = *max_element(a.begin() + al, a.begin() + ar);
      vector<int> idx;
      idx.push_back(al - 1);
      for (int j = al; j < ar; j++){
        if (a[j] == mx){
          idx.push_back(j);
        }
      }
      idx.push_back(ar);
      int cnt = idx.size();
      for (int j = 1; j < cnt - 1; j++){
        if (bl <= idx[j] && idx[j] < br){
          if (b[idx[j]] != mx){
            return false;
          }
        }
      }
      for (int j = 0; j < cnt - 1; j++){
        int L = idx[j] + 1;
        int R = idx[j + 1];
        L = clamp(L, bl, br);
        R = clamp(R, bl, br);
        if (L < R){
          if (j > 0){
            while (L < R && b[L] == mx){
              L++;
            }
          }
          if (j < cnt - 2){
            while (L < R && b[R - 1] == mx){
              R--;
            }
          }
          if (L < R){
            if (!dfs(dfs, idx[j] + 1, idx[j + 1], L, R)){
              return false;
            }
          }
        }
      }
      return true;
    };
    if (dfs(dfs, 0, n, 0, n)){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
