#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++)
    cin >> A[i];
  stack<pair<int,int>> st;
  vector<int> left(n, -1), right(n, n);
  for (int i=0;i<n;i++){
    while (!st.empty() && st.top().second >= A[i])
      st.pop();
    if (!st.empty()) left[i] = st.top().first;
    st.push({i,A[i]});
  }
  while(!st.empty()) st.pop();
  for (int i=n-1;i>=0;i--){
    while (!st.empty() && st.top().second > A[i])
      st.pop();
    if (!st.empty()) right[i] = st.top().first;
    st.push({i,A[i]});
  }
  ll ans = 0;
  for (int i=0;i<n;i++){
    ans = max(ans, (ll)A[i]*(right[i] - left[i]-1));
  }
  cout << ans << "\n";
}
