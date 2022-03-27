#include <cstdio>
#include <algorithm>
#include <limits>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

#define N 200001
#define QueueItem pair<int, tuple<int, int, int> >
long long INF = numeric_limits<long long>::max();
long long INTINF = numeric_limits<int>::max();
vector< pair<int, int> > graph[N];
long long dis[N][2][2];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    priority_queue<QueueItem, vector<QueueItem>, greater<QueueItem>> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 2; ++j) 
            for (int k = 0; k < 2; ++k)
                dis[i][j][k] = INF;
    dis[1][0][0] = 0;
    q.push({0, {1, 0, 0}});
    while (!q.empty()) {
        const auto item = q.top().second;
        const auto d = q.top().first;
        const auto [u, del, add] = item;
        q.pop();
        if (dis[u][del][add] < d) continue;
        for (auto [v, cost] : graph[u]) {
            for (int i = 0; i < 2-del; ++i) {
                for (int j = 0; j < 2-add; ++j) {
                    long long newdis = dis[u][del][add] + cost;
                    if (i == 1) newdis -= cost;
                    if (j == 1) newdis += cost;
                    if (newdis < dis[v][del|i][add|j]) {
                        dis[v][del|i][add|j] = newdis;
                        q.push({newdis, {v, del|i, add|j}});
                    }
                }
            }
        }

    }

    for (int i = 2; i <= n; ++i) {
        cout << dis[i][1][1] << " ";
    }
    cout <<endl;
    return 0;
}