#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAXN 200005

int arr[MAXN];
int last[MAXN];
bool used[MAXN];

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {  
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    last[arr[i]] = i;
  }

  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
  for (int i = 1; i <= k; i++)
  {
    pq.push({last[i], i});
  }

  int l = 0;
  for (int i = 0; i < k; i++)
  {
    while (used[pq.top().second])
    {
      pq.pop();
    }

    int minIndex = pq.top().first;
    for (int j = l; j <= pq.top().first; j++)
    {
      if (used[arr[j]])
        continue;
      
      if (arr[minIndex] > arr[j] || (arr[minIndex] == arr[j] && j < minIndex))
      {
        minIndex = j;
      }
    }

    l = minIndex + 1;
    used[arr[minIndex]] = true;
    cout << arr[minIndex] << " ";
  }
  cout << endl;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}


#ifdef VERSION > 10
if (NewAPICall()) {
#else
if (OldAPICall()) {
#endif
}