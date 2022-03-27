#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;
// We can't use dijkstra here
// Since length of path can be smaller than length of subpath.
// - max w_i + min w_i 
// min w in Q_x is bigger than or equal to min w in Q
// If length of subpath is bigger, 
//  there might exist some path outside R (visited vertexs) to u (current vertex)
//    its length smallar than d[u] 

struct Edge {
    int v;
    int u;
    int cost;
};

struct Sketch {
    int maxw;
    int minw;
};
long long INF = numeric_limits<long long>::max();
long long INTINF = numeric_limits<int>::max();
int main() {

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m*2);
    for (int i = 0; i < m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        Edge e1 = {v, u, w};
        Edge e2 =  {u, v, w};
        edges[i] = e1;
        edges[m + i] = e2;
    }
    long long dis[200001];
    Sketch sketch[200001];
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
        // nextdis[i] = INF;
        sketch[i].maxw = -1;
        // nextsketch[i].maxw = -1;
        // nextsketch[i].minw = INTINF;
        sketch[i].minw = INTINF;
    }
    dis[1] = 0;
    // nextdis[1] = 0;
    for (int t = 0; t < n*4; ++t) {
        for (int i = 0; i < m*2; ++i) {
            const auto& e = edges[i];
            if (dis[e.u] != INF) {
                const auto newmax = max(sketch[e.u].maxw, e.cost);
                const auto newmin = min(sketch[e.u].minw, e.cost);
                auto newdis = dis[e.u] + e.cost - newmax + newmin;
                if (sketch[e.u].minw != INTINF) newdis += sketch[e.u].maxw - sketch[e.u].minw;
                if (newdis < dis[e.v]) {
                    dis[e.v] = newdis;
                    sketch[e.v].maxw = newmax;
                    sketch[e.v].minw = newmin;
                } else if(newdis == dis[e.v]) {
                    dis[e.v] = newdis;
                    sketch[e.v].maxw = max(newmax, sketch[e.v].maxw);
                    sketch[e.v].minw = min(newmin, sketch[e.v].minw);
                }
            }
        }
    }
     for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout <<endl;
    return 0;
}