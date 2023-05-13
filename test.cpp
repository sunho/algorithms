#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
int k1, k2;

void dfsSize(int cur, int prev)
{
    for (int next : adj[cur])
    {
        if (next == prev)
            continue;
        dfsSize(next, cur);
    }
}

int main()
{
    freopen("test_input.txt", "r", stdin);
    int n;
    cin >> n >> k1 >> k2;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfsSize(1, 0);

    cout << "A" << endl;
}