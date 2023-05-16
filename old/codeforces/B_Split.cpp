#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;

  vector<int> cols = {3,2,4,1,3,5,0,2,4,6};

  vector<int> nums(7);

  for (int i=0;i<10;i++){
    if (s[i] == '1') {
      nums[cols[i]]++;
    }
  }
  if (s[0] == '1') {
    cout << "No" << "\n";
    return 0;
  }
  bool ok = false;
  for (int i=0;i<7;i++){
    for (int j=i+2;j<7;j++){
      if (!nums[i] || !nums[j]) continue;
      for (int z=i+1;z<j;z++){
        if (!nums[z]) ok = true;
      }
    }
  }
  if (ok) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}

