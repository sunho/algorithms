#include <bits/stdc++.h>

using namespace std;

int main() {
  int cur;
  cin >> cur;
  auto query = [&](string s) {
    cout << "? " << s << endl;
    cout << flush;
    int nw;
    cin >> nw;
    return nw;
  };
  string s(100, '2');
  for (int i=0;i<100;i++){
    string s2(100, '2');
    s2[i] = '0';
    int nw = query(s2);
    int d = nw-cur;
    if (d == 1) {
      s[i] = '2';
    } else if (d == 0) {
      s[i] = '0';
    } else if (d == -1){
      s[i] = '5';
    } else {
      assert(false);
    }
  }
  cout << "! " << s << endl;
  cout << flush;
}
