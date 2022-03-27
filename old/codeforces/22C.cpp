#include <iostream>

#define For(i,s,n) for(int i =(s); i < (n); ++i)
#define ll long long
using namespace std;

ll n, m, v;
bool check() {
        if (m < n - 1) {
                return false;
        }
        if (n == 3 && m > 2) {
                return false;
        }
        // (n-2) 개의 정점을 가진 컴포넌트의 간선 수 + v 정점과 연결된 간선 수
        if (m > (n - 2) * (n - 3) / 2 + n - 1) {
                return false;
        }
        return true;
}

void print(ll a, ll b) {
        if (a < b) cout << a << " " << b << endl;
        else cout << b << " " << a << endl;
}

void printGroup(ll exp) {
        For(i, 1, n + 1) {
                if (i == v || i == exp) continue;
                For(j, i + 1, n + 1) {
                        if (j == v || j == exp) continue;
                        if (m == 0) return;
                        m --;
                        print(i, j);
                }
        }
}

int main() {
        cin >> n >> m >> v;
        if (!check()) {
                cout << -1;
                return 0;
        }

        // v 정점
        For(i, 1, n + 1) {
                if (i == v) continue;
                print(v, i);
        }
        m -= n - 1;

        // 컴포넌트
        if (v != 1) printGroup(v - 1);
        else printGroup(v + 1);

        return 0;
}
