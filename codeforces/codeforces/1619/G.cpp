#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define x first
#define y second
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(x,a) for(auto& x : (a))
#define endl '\n'
template<class T> bool ckmin(T&a, const T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T&b) { bool B = a < b; a = max(a,b); return B; }
template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }

#define inf (1e9+5)

struct DSU {
    vector<int> e;
    vector<int> p;
    vector<int> t;
    int scc;

    DSU(int N) { 
        e.assign(N, 1);
        p.assign(N, 0);
        t.assign(N, 0);
        rep(i, 0, N) p.at(i) = i;
        rep(i, 0, N) t.at(i) = inf;
        scc = N;
    }

	// get representive component (uses path compression)
	int get(int x) { 
        if (x == p.at(x)) return x;
        return p.at(x) = get(p.at(x));
    }
    bool is_rep(int x) { return p.at(x) == x; }
    void set_t(int x, int j) { 
        t.at(x) = j;
    }
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return e.at(get(x)); }
    int time(int x) { return t.at(get(x)); }
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e.at(x) < e.at(y)) 
            swap(x, y);
		e.at(x) += e.at(y);
        t.at(x) = min(t.at(x), t.at(y));
        p.at(y) = x;
        scc--;
        return true;
	}
};

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        cin >> n >> k;
        DSU G(n);
        map<int, map<int, int>> Mx;
        map<int, map<int, int>> My;
        auto connect = [&](map<int, map<int, int>>&M, int x, int y, int v) {
             if (M.count(x)) {
                auto it = M[x].lower_bound(y);
                if (it != M[x].end()) {
                    if (it->x - y <= k) {
                        G.unite(v, it->y);
                    }
                }
                if (it != M[x].begin()) {
                    --it;
                    if (y - it->x <= k) {
                        G.unite(v, it->y);
                    }
                }
            }
        };
        rep(i, 0, n) {
            int x,y,t;
            cin >> x >> y >> t;
            G.set_t(i, t);
            connect(Mx, x, y, i);
            connect(My, y, x, i);
            Mx[x][y] = i;
            My[y][x] = i;
        }
        vi T;
        rep(i, 0, n) {
            if (G.is_rep(i)) {
                T.push_back(G.time(i));
            }
        }
        sort(all(T));
        deque<int> deq(all(T));
        int t = 0;
        while (!deq.empty()) {
            auto it = deq.begin();
            while (it != deq.end()) { 
                if (*it > t) {
                    break;
                }
                it = deq.erase(it);
            }
            if (deq.empty()) break;
            deq.pop_back();
            if (!deq.empty()) t++;
        }
        cout << t << '\n';
    }



    return 0;
}
