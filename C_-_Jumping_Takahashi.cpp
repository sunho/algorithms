#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N,X;
  cin >> N >> X;
  vector<int> A(N), B(N);
  for(int i=0;i<N;i++) cin >> A[i], cin >> B[i];

  vector<bool> prev(X+1);
  prev[0] = true; // Takahashi was initially at x = 0
  for(int t=0;t<N;t++){
    vector<bool> current(X+1);
    for(int x=0;x<X;x++){
      if (prev[x]) { // if it was possible to reach x in the previous turn
        if (x+A[t] <= X) 
          current[x+A[t]] = true; // mark x + A[t] as possible
        if (x+B[t] <= X)
          current[x+B[t]] = true; // makr x + B[t] as possible
      }
    }
    prev = move(current);
  }

  if (prev[X]) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}

int main() {
  solve();

  return 0;
}
