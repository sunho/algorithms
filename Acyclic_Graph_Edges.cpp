#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  while (m--){
    int a,b;
    cin >> a >> b;
    if (a>b) swap(a,b);
    cout << a << " " << b << "\n";
  }
}
