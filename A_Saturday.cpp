#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  vector<string> weekdays = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
  string s;
  cin >> s;
  int i = find(weekdays.begin(), weekdays.end(), s) - weekdays.begin();
  cout << 5 - i << "\n";
}
