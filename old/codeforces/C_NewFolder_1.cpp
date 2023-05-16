#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  map<string, int> cnt;
  for (int i=0;i<n;i++){
    string s;
    cin >> s;
    if (cnt[s] == 0) {
      cout << s << "\n";
    } else {
      cout << s << "(" << cnt[s] << ")\n";
    }
    cnt[s]++;
  }
}
