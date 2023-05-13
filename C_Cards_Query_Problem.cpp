#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  int q;
  cin >> q;
  vector<multiset<int>> box(n+1);
  map<int, set<int>> cards;
  while (q--){
    int t;
    cin >> t;
    if (t == 1) {
      int i,j;
      cin >> i >> j;
      box[j].insert(i);
      cards[i].insert(j);
    } else if (t == 2) {
      int i;
      cin >> i;
      for (int v : box[i]) {
        cout << v << " ";
      }
      cout << "\n";
    } else {
      int i;
      cin >> i;
      for (int v : cards[i]) {
        cout << v << " ";
      }
      cout << "\n";
    }
  }
}
