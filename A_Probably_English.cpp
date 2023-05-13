#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  vector<string> S = {"and","not","that","the","you"};
  int n;
  cin >> n;
  while (n--){
    string s;
    cin >> s;
    if (find(S.begin(), S.end(), s) != S.end()) {
      cout << "Yes" << "\n";
      return 0;
    }
  }
  cout << "No" << "\n";
}
